Este proyecto es la extensión del sistema de gestión hospitalaria (Taller 1), implementando un sistema automático de triaje basado en un Árbol Binario de Decisión y el almacenamiento de pacientes en Árboles AVL auto-balanceables clasificados por servicio médico.
Integrantes: 
Antonio Arancibia --- Nombre Usuario: Antonyyhh --- Carrera: ICCI --- Paralelo: C1
Dante Pizarro --- Nombre Usuario: dantepizarro --- Carrera: ICCI --- Paralelo: C1
Este proyecto está diseñado para compilarse sin dependencias externas en cualquier entorno que soporte g++ (como Linux, WSL, MinGW en Windows o Codespace).
Use este comando para enlazar todos los archivos: g++ -o hospital main.cpp Paciente.cpp ColaPacientes.cpp ListaServicio.cpp ArbolDesicion.cpp ArbolAVL.cpp
Y para ejecutar el codigo en Codespace use este: ./hospital
Diseño y Justificación del Árbol de Decisión (Triaje)

El sistema evalúa automáticamente a cada paciente utilizando un árbol binario de decisión que filtra los casos de mayor a menor especialidad o riesgo. La lógica implementada (y su justificación médica conceptual) es la siguiente:

Nodo 1 (Edad < 14):

Sí -> Pediatría: Cualquier paciente menor de 14 años es derivado inmediatamente a atención pediátrica especializada, independientemente de sus síntomas.

No -> Continúa la evaluación para adultos.

Nodo 2 (Trauma == 1):

Evalúa si el paciente ingresa con algún tipo de trauma físico.

Sí -> Pasa al Nodo 3 (Cirugía).

No -> Pasa al Nodo 4 (Neurología).

Nodo 3 (Requiere Cirugía == 1): (Derivado de trauma)

Sí -> Cirugía: Si el trauma es lo suficientemente severo para requerir intervención quirúrgica.

No -> Traumatología: Si es un trauma (ej. fractura o esguince) que no requiere entrar a pabellón de inmediato.

Nodo 4 (Síntomas Neurológicos == 1):

Sí -> Neurología: Se prioriza la atención neurológica si no hay trauma evidente pero sí compromiso del sistema nervioso (ej. ACV).

No -> Pasa al Nodo 5 (Dolor).

Nodo 5 (Tipo Dolor == "pecho"):

Sí -> Cardiología: El dolor de pecho se intercepta rápidamente por protocolo como posible riesgo de infarto.

No -> Pasa al Nodo 6 (Urgencia General).

Nodo 6 (Fiebre >= 38.5, Dolor >= 8 o Presión Crítica):

Sí -> Urgencias: Si el paciente presenta un cuadro agudo (fiebre alta, dolor extremo, hipotensión < 90 o hipertensión > 180), requiere estabilización inmediata.

No -> Pasa al Nodo 7 (Evaluación de estadía).

Nodo 7 (Días Hospitalización >= 2):

Sí -> Hospitalización: Casos estables pero que requieren monitoreo y pernoctar en el recinto.

No -> Medicina General: Consultas de baja complejidad, sin riesgo vital y de carácter ambulatorio.

Carga de pacientes desde pacientes.txt , cola de pacientes pendientes implementada con nodos y punteros, arbol de decision implementado tambien con nodos y punteros, con recorridos y ruta de decision, lista enlazada de los 8 servicios, cada uno con su propio AVL, AVL en base al ID, rotaciones simples y dobles, operaciones del AVL como insertar, buscar por ID, buscar por nombre, recorridos preorden, inorden y preorden, altura y factor de balance
Arbol decision:

Edad < 14?
si -> Pediatria
no -> trauma == 1?
  si -> RequiereCirugia == 1?
      si -> Cirugia
      no -> Traumatologia
  no-> SintomasNeurologicos == 1?
      si -> Neurologia
      no -> TipoDolor == "pecho"?
            si -> Cardiologia
            no -> Temperatura >= 38.5 o Dolor >= 8 o Presion < 90 o presion > 180?
                  si -> Urgencias
                  no -> DiasHospitalizacion >= 2?
                        si -> Hospitalizacion
                        no -> Medicina General

Uso:
1. Atender pacientes: atiende un paciente, el siguiente en la cola, muestra su ficha. la ruta del arbol de decision, el servicio asignado y lo inserta en el AVL de ese servicio
2. Ver departamentos: muestra el estado de los 8 servicios
3. Buscar pacientes: busca por ID o por nombre en los 8 AVL, al encontrarlo muestra su ficha, su departamento, y si se busco por ID, la ruta de busqueda

Se decidio que la opcion 1 se atienda un solo paciente por vez
