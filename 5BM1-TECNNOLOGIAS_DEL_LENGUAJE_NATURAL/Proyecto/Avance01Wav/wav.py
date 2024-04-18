import struct
import cmath
import numpy as np
import matplotlib.pyplot as plt

class WavHeader:
    def __init__(self):
        self.RIFF = b''
        self.ChunkSize = 0
        self.WAVE = b''
        self.fmt = b''
        self.Subchunk1Size = 0
        self.AudioFormat = 0
        self.NumOfChan = 0
        self.SamplesPerSec = 0
        self.bytesPerSec = 0
        self.blockAlign = 0
        self.bitsPerSample = 0
        self.Subchunk2ID = b''
        self.Subchunk2Size = 0

def get_file_size(file):
    file.seek(0, 2)
    file_size = file.tell()
    file.seek(0)
    return file_size

def fft(x):
    N = len(x)
    if N <= 1:
        return x
    else:
        # Rellena la señal con ceros si su longitud no es potencia de 2
        if N % 2 != 0:
            x.extend([0] * (2**((N-1).bit_length()) - N))
            N = len(x)
        even = fft(x[::2])
        odd = fft(x[1::2])
        T = [cmath.exp(-2j * cmath.pi * k / N) * odd[k] for k in range(N // 2)]
        return [even[k] + T[k] for k in range(N // 2)] + \
               [even[k] - T[k] for k in range(N // 2)]

def main():
    wav_header = WavHeader()
    header_size = struct.calcsize('<4sI4s4sIHHIIHH4sI')
    file_length = 0

    file_path = input("Input wave file name: ").strip()

    with open(file_path, 'rb') as wav_file:
        wav_header_data = wav_file.read(header_size)
        (
            wav_header.RIFF,
            wav_header.ChunkSize,
            wav_header.WAVE,
            wav_header.fmt,
            wav_header.Subchunk1Size,
            wav_header.AudioFormat,
            wav_header.NumOfChan,
            wav_header.SamplesPerSec,
            wav_header.bytesPerSec,
            wav_header.blockAlign,
            wav_header.bitsPerSample,
            wav_header.Subchunk2ID,
            wav_header.Subchunk2Size
        ) = struct.unpack('<4sI4s4sIHHIIHH4sI', wav_header_data)

        print(f"Header Read {header_size} bytes.")

        bytes_per_sample = wav_header.bitsPerSample // 8
        num_samples = wav_header.ChunkSize // bytes_per_sample
        buffer_size = 4096
        buffer = bytearray(buffer_size)

        time_samples = []

        while True:
            bytes_read = wav_file.readinto(buffer)
            if not bytes_read:
                break

            time_samples.extend(struct.unpack('<{}h'.format(bytes_read // 2), buffer[:bytes_read]))

        #print("Espectro en tiempo:")
        #print(time_samples)

        # Crear un array de tiempo para el eje x
        time = np.arange(0, len(time_samples) / wav_header.SamplesPerSec, 1 / wav_header.SamplesPerSec)

        print("Longitud de time:", len(time))
        print("Longitud de time_samples:", len(time_samples))


        # Espectro en frecuencia (FFT)
        freq_spectrum = fft(time_samples)
        #print("Espectro en frecuencia:")
        #print(freq_spectrum)

        # Graficar espectro en tiempo
        plt.figure(figsize=(10, 5))
        plt.subplot(2, 1, 1)
        plt.plot(time, time_samples[:len(time)])
        plt.title('Espectro en Tiempo')
        plt.xlabel('Muestras')
        plt.ylabel('Amplitud')

        # Graficar espectro en frecuencia
        plt.subplot(2, 1, 2)
        plt.plot(np.abs(freq_spectrum))
        plt.title('Espectro en Frecuencia')
        plt.xlabel('Frecuencia')
        plt.ylabel('Amplitud')

        plt.tight_layout()
        plt.show()

        file_length = get_file_size(wav_file)

        print(f"File is                    : {file_length} bytes.")
        print(f"RIFF header                : {wav_header.RIFF.decode()}")
        print(f"WAVE header                : {wav_header.WAVE.decode()}")
        print(f"FMT                        : {wav_header.fmt.decode()}")
        print(f"Data size                  : {wav_header.ChunkSize}")
        print(f"Sampling Rate              : {wav_header.SamplesPerSec}")
        print(f"Number of bits used        : {wav_header.bitsPerSample}")
        print(f"Number of channels         : {wav_header.NumOfChan}")
        print(f"Number of bytes per second : {wav_header.bytesPerSec}")
        print(f"Data length                : {wav_header.Subchunk2Size}")
        print(f"Audio Format               : {wav_header.AudioFormat}")
        print(f"Block align                : {wav_header.blockAlign}")
        print(f"Data string                : {wav_header.Subchunk2ID.decode()}")

if __name__ == "__main__":
    main()
