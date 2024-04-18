import cv2
import numpy as np
import matplotlib.pyplot as plt

# prewitt filter

def prewitt_filter(img, K_size=3):
    H, W = img.shape

    # Zero padding

    pad = K_size // 2
    out = np.zeros((H + pad * 2, W + pad * 2), dtype=float)
    out[pad: pad + H, pad: pad + W] = img.copy().astype(float)
    tmp = out.copy()
    out_v = out.copy()
    out_h = out.copy()
    ## prewitt vertical kernel
    Kv = [[-1., -1., -1.],[0., 0., 0.], [1., 1., 1.]]
    ## prewitt horizontal kernel
    Kh = [[-1., 0., 1.],[-1., 0., 1.],[-1., 0., 1.]]
    # filtering
    for y in range(H):
        for x in range(W):
            out_v[pad + y, pad + x] = np.sum(Kv * (tmp[y: y + K_size, x: x + K_size]))
            out_h[pad + y, pad + x] = np.sum(Kh * (tmp[y: y + K_size, x: x + K_size]))
    
    out_v = np.clip(out_v, 0, 255)
    out_h = np.clip(out_h, 0, 255)
    out_v = out_v[pad: pad + H, pad: pad + W].astype(np.uint8)
    out_h = out_h[pad: pad + H, pad: pad + W].astype(np.uint8)

    return out_v, out_h

# Read Gray image
img = cv2.imread(r"C:\Users\lenovo\Desktop\CODIGOS_FUENTES\4BM2-PROCESAMIENTO_DIGITAL_DE_IMAGENES\OperadorPrewit\Imagenes\right.jpg",0).astype(float)
# prewitt filtering
out_v, out_h = prewitt_filter(img, K_size=3)
# Save result
# Guardar la imagen vertical (out_v) en un archivo JPEG
cv2.imwrite("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-PROCESAMIENTO_DIGITAL_DE_IMAGENES\\OperadorPrewit\\Resultados\\rightPrewitOut_v.jpg", out_v)

# Guardar la imagen horizontal (out_h) en un archivo JPEG
cv2.imwrite("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-PROCESAMIENTO_DIGITAL_DE_IMAGENES\\OperadorPrewit\\Resultados\\rightPrewitOut_h.jpg", out_v)

# Crear una figura y subtramas
fig, axs = plt.subplots(1, 2, figsize=(10, 5))

# Mostrar la imagen vertical en la primera subtrama
axs[0].imshow(out_v, cmap='gray')
axs[0].set_title('Vertical')

# Mostrar la imagen horizontal en la segunda subtrama
axs[1].imshow(out_h, cmap='gray')
axs[1].set_title('Horizontal')

# Mostrar el título de la figura
fig.suptitle('Imágenes Prewitt')

# Ajustar el espacio entre subtramas
plt.tight_layout()

# Mostrar la figura
plt.show()

#Cerrar figuras
plt.close()