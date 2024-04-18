class WavHeader:
    def __int__(self):
        self.RIFF = b'' #Etiqueta del formato del archivo
        self.ChunkSize = 0 #Cantidad de Chunks dentro del WAV
        self.WAVE = b''
        self.fmt = b'' #Formato del archivo
        self.Subchunk
