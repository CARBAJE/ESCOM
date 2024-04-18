import struct

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

        while True:
            bytes_read = wav_file.readinto(buffer)
            if not bytes_read:
                break

            # Hacer algo con los datos de audio aquí
            #print(f"Read {bytes_read} bytes.")

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
