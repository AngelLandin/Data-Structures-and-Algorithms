from fpdf import FPDF # type: ignore

# Define the content with replacements for unicode characters
user_request = "Quiero que me expliques que es el campo eléctrico pero primero dame una explicación técnica nivel ingeniería universitaria y posteriormente explícamelo de manera simple con analogías y también con algún videojuego, gracias."
technical_explanation = """### Explicación Técnica (Nivel Ingeniería Universitaria)

El **campo eléctrico** es una magnitud vectorial que describe la fuerza eléctrica que actúa sobre una carga puntual en cada punto del espacio. Se define como la fuerza que experimenta una carga de prueba positiva dividida por el valor de dicha carga, es decir:

E = F / q

donde:
- E es el campo eléctrico (en N/C o V/m),
- F es la fuerza ejercida sobre la carga,
- q es el valor de la carga de prueba.

Este campo se origina en cargas eléctricas y puede describirse mediante las ecuaciones de Maxwell. En particular, la ley de Coulomb para una carga puntual Q establece que el campo eléctrico a una distancia r es:

E = (1/(4*pi*epsilon_0)) * (Q/r^2) * r_hat

donde:
- epsilon_0 es la permitividad del vacío,
- r_hat es el vector unitario que apunta desde la carga Q hacia el punto de interés.

Además, el campo eléctrico es conservativo en ausencia de campos variables en el tiempo, lo que significa que se puede definir un potencial eléctrico V tal que:

E = -grad(V)

Esta relación implica que la diferencia de potencial entre dos puntos es independiente del camino recorrido, permitiendo el uso de métodos de integración para determinar energías y trabajos en sistemas electrostáticos.
"""

simple_explanation = """### Explicación Sencilla con Analogías y Ejemplo de Videojuego

Imagina que el campo eléctrico es como un 'campo de fuerzas invisible' que se extiende por el espacio. Cada punto de este campo tiene una dirección y una intensidad, similar a las flechas en un mapa que indican hacia dónde sopla el viento y con qué fuerza.

Analogía simple:
- Analogía con el viento: Piensa en estar al aire libre en un día ventoso. El viento ejerce una fuerza sobre ti, empujándote en una dirección. En el caso del campo eléctrico, en lugar de viento, tienes 'fuerzas invisibles' que empujan o tiran de una carga eléctrica. Si colocas una pequeña bolita (la carga de prueba) en este 'viento eléctrico', la dirección y la fuerza con la que se mueve dependen de la dirección y fuerza del campo en ese lugar.

Analogía con videojuegos:
- Ejemplo en un videojuego: Considera un juego de plataformas o de acción, donde en algunas áreas del mapa hay zonas de 'magia' o 'fuerza' que pueden empujar al personaje o hacerlo flotar, como en algunos niveles de Super Mario o Portal. En estos niveles, al entrar en una zona determinada, sientes que el entorno te empuja en una dirección específica, similar a cómo el campo eléctrico influye en la trayectoria de una carga. La 'zona de fuerza' es análoga a una región del espacio en la que el campo eléctrico tiene una intensidad y dirección definidas, y el 'personaje' (la carga) reacciona a esas fuerzas invisibles.

En resumen, el campo eléctrico en la ingeniería es una herramienta matemática y física fundamental para describir interacciones entre cargas, mientras que en términos cotidianos es como un 'viento invisible' que afecta el movimiento de las cargas, similar a zonas de fuerza en ciertos videojuegos que modifican el comportamiento del personaje.
"""

full_content = "Solicitud del usuario:\n" + user_request + "\n\n" + technical_explanation + "\n\n" + simple_explanation

# Replace problematic unicode characters
full_content = full_content.replace("“", "\"").replace("”", "\"").replace("‘", "'").replace("’", "'")

# Create a PDF
pdf = FPDF()
pdf.add_page()
pdf.set_auto_page_break(auto = True, margin = 15)
pdf.set_font("Arial", size = 12)

for line in full_content.split('\n'):
    pdf.multi_cell(0, 10, txt=line)

pdf_file_path = "/mnt/data/explicacion_campo_electrico.pdf"
pdf.output(pdf_file_path)
print("PDF guardado en:", pdf_file_path)
