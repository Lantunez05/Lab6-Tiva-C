#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  Serial.begin(9600);  // Configura la comunicación serial a 9600 baudios
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
 
  SPI.setModule(0);
  Serial.print("Initializing SD card...");
  pinMode(12, OUTPUT);

  if (!SD.begin(12)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

}

void loop() {
  Serial.println("Seleccione una opción:");
  Serial.println("1) Imprimir 'Caballo ajedrez'");
  Serial.println("2) Imprimir 'MK Scorpion'");
  Serial.println("3) Imprimir 'Poste de luz'");
  Serial.println("4) Crea tu propia imagen");

  while (!Serial.available()) {
    // Espera a que el usuario ingrese una opción
  }

  int opcion = Serial.parseInt();  // Lee la opción ingresada por el usuario

  // Realiza la acción correspondiente según la opción seleccionada
  switch (opcion) {
    case 1:
      Serial.println("Caballo ajedrez");
      mostrarImagen("Caballo.txt");
      break;
    case 2:
      Serial.println("MK Scorpion");
      mostrarImagen("Scorpion.txt");
      break;
    case 3:
      Serial.println("Poste de luz");
      mostrarImagen("lab6.txt");
      break;
    case 4: 
      Serial.println("Crea una imagen");
      crearImagen("lab6.txt");
      break;
    default:
      Serial.println("Opción no válida.");
      break;
  }

  // Limpia el búfer serial
  while (Serial.available()) {
    Serial.read();
  }
}

void mostrarImagen(const char *nombreArchivo) {
  File archivo = SD.open(nombreArchivo);

  if (archivo) {
    while (archivo.available()) {
      Serial.write(archivo.read()); // Lee y envía el contenido del archivo al monitor serial
    }
    archivo.close();
  } else {
    Serial.println("Error al abrir el archivo.");
  }
}

void crearImagen(const char *nombreArchivo) {
  File archivo = SD.open(nombreArchivo, FILE_WRITE); // Abre el archivo en modo escritura

  if (archivo) {
      Serial.print("Crea tu imagen(recuerda terminar con '#'): ");
      while(1){
        while(!Serial.available());
        char caracter = Serial.read(); // Lee un carácter desde la comunicación serial
        if (caracter == '#') {
          archivo.println("\nTexto guardado en el archivo.");
          archivo.close(); // Cierra el archivo cuando se encuentra el carácter '#'
          Serial.println("Archivo creado y texto guardado.");
          return; // Salir del bucle
        } else {
          archivo.print(caracter); // Escribe el carácter en el archivo
        }
      }   
  } else {
    Serial.println("Error creando el archivo.");
  }
}
