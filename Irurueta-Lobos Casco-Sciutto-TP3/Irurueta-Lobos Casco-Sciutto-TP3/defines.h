#pragma once
#define cantCATEGORIAS 4

#define ALQUILER_AUTOMOVILES 1000
#define ALQUILER_MOTOCICLETAS 700
#define ALQUILER_CAMIONETAS 1500
#define ALQUILER_TRAFICS 1700

#define ESmaxAUTOMOVIL 1
#define ESmaxMOTOCICLETA 1
#define ESmaxTRAFIC 2
#define ESmaxCAMIONETA 2

#define pasajerosMaxAUTOMOVIL 5
#define pasajerosMaxMOTOCICLETA 2
#define pasajerosMaxCAMIONETA 7
#define pasajerosMaxTRAFIC 7

#define CASCOSmax 2
#define SILLAS_NINOSmax 3
#define ASIENTOSmax 3
#define PORTAEQUIPAJESmax 1

#define PrecioSILLA 50
#define PrecioCASCO 50
#define PrecioPORTAEQUIPAJE 100
#define PrecioASIENTO 70

#define PrecioCompraAUTOMOVIL 10000
#define PrecioCompraMOTOCICLETA 7000
#define PrecioCompraTRAFIC 12000
#define PrecioCompraCAMIONETA 11000

const string pasosMantenimientoAUTOMOVIL = "\n1. Luces\n2. Chasis\n3. Seguridad y Emergencia\n4. Sistema de direccion y Tren delantero\n5. Sistema de escape\n6. Sistema de Frenos\n7. Neumaticos\n8. Sistema de suspension";
const string pasosMantenimientoMOTOCICLETA = "\n1. Espejos\n2. Luces\n3. Bocina\n4. Placa de dominio\n5. Nivel sonoro(escape)\n6. Emision de gases(escape)\n7. Cubrecadena\n8. Chasis\n9. Frenos\n10. Neumaticos";
const string pasosMantenimientoCAMIONETA = "\n1. Luces\n2. Chasis\n3. Seguridad y Emergencia\n4. Sistema de direccion y Tren delantero\n5. Sistema de escape\n6. Sistema de Frenos\n7. Neumaticos\n8. Sistema de suspension";
const string pasosMantenimientoTRAFIC = "\n1. Luces\n2. Chasis\n3. Seguridad y Emergencia\n4. Sistema de direccion y Tren delantero\n5. Sistema de escape\n6. Sistema de Frenos\n7. Neumaticos\n8. Sistema de suspension";

const string CATEGORIAS[cantCATEGORIAS] = {
	"automovil",
	"motocicleta",
	"trafic",
	"camioneta"
};
