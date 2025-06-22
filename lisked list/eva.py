import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def plot_ellipsoid(ax, center, radii, color='white', alpha=1.0):
    """
    Dibuja un elipsoide en 3D.
    center: (x0, y0, z0)
    radii: (rx, ry, rz)
    """
    u = np.linspace(0, 2 * np.pi, 50)
    v = np.linspace(0, np.pi, 50)
    
    x = radii[0] * np.outer(np.cos(u), np.sin(v)) + center[0]
    y = radii[1] * np.outer(np.sin(u), np.sin(v)) + center[1]
    z = radii[2] * np.outer(np.ones_like(u), np.cos(v)) + center[2]
    
    ax.plot_surface(x, y, z, color=color, alpha=alpha, edgecolor='none')

# Crear figura y ejes 3D
fig = plt.figure(figsize=(8, 8))
ax = fig.add_subplot(111, projection='3d')

# ----- CUERPO (elipsoide grande) -----
# EVA es como un huevo alargado. Ajusta los radios para cambiar la forma.
body_center = (0, 0, 0)  # centro del cuerpo
body_radii  = (1.2, 1.2, 1.8)  # rx, ry, rz (más alto en z)
plot_ellipsoid(ax, body_center, body_radii, color='silver', alpha=0.8)

# ----- CABEZA (elipsoide pequeño) -----
# Ponemos la cabeza arriba del cuerpo, ajustando el centro en z.
head_center = (0, 0, body_radii[2] * 0.8)  # un poco arriba del tope del cuerpo
head_radii  = (0.6, 0.6, 0.5)
plot_ellipsoid(ax, head_center, head_radii, color='skyblue', alpha=0.9)

# ----- BRAZOS (dos elipsoides pequeños a los lados) -----
# Ajustamos la posición para que queden a los costados.
arm_radii = (0.3, 0.3, 0.5)  # un poco alargados
# Brazo derecho
arm_right_center = (body_radii[0] + 0.3, 0, 0.5)  # un poco a la derecha en X, algo en Z
plot_ellipsoid(ax, arm_right_center, arm_radii, color='lightgreen', alpha=0.9)
# Brazo izquierdo
arm_left_center  = (-body_radii[0] - 0.3, 0, 0.5) # un poco a la izquierda en X
plot_ellipsoid(ax, arm_left_center, arm_radii, color='lightgreen', alpha=0.9)

# ----- AJUSTES FINALES DE LA GRÁFICA -----
ax.set_xlim(-3, 3)
ax.set_ylim(-3, 3)
ax.set_zlim(-1, 4)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('Modelo Simplificado de EVA con Elipsoides')
ax.view_init(elev=20, azim=30)

plt.show()
