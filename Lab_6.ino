void setup() {
  Serial.begin(9600);  // Configura la comunicación serial a 9600 baudios
}

void loop() {
  Serial.println("Seleccione una opción:");
  Serial.println("1) Imprimir 'Hola'");
  Serial.println("2) Imprimir 'Como'");
  Serial.println("3) Imprimir 'Estas'");

  while (!Serial.available()) {
    // Espera a que el usuario ingrese una opción
  }

  int opcion = Serial.parseInt();  // Lee la opción ingresada por el usuario

  // Realiza la acción correspondiente según la opción seleccionada
  switch (opcion) {
    case 1:
      Serial.println("Hola");
      break;
    case 2:
      Serial.println("Como");
      break;
    case 3:
      Serial.println("Estas");
      break;
    default:
      Serial.println("Opción no válida. Intente de nuevo.");
      break;
  }

  // Limpia el búfer serial
  while (Serial.available()) {
    Serial.read();
  }
}
