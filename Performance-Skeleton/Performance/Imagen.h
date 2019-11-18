#pragma once

/* Imagen de tama�o fijo. Sirve como ejemplo de clase "pesada". */
class Imagen
{
public:
	/* Constructor por defecto. */
	Imagen();

	/* Constructor por copia. */
	Imagen(const Imagen &imagen);

	/* Destructor. */
	virtual ~Imagen();

	/* Operador de asignaci�n. */
	Imagen& operator=(const Imagen &imagen);
	
	/* Operador de pre-incremento. */
	Imagen& operator++(); 

	/* Operador de post-incremento. */
	Imagen operator++(int); 

	/* Intercambia el contenido de dos im�genes. */
	void swap(Imagen &imagen);

private:
	/* Vector de pixels, para simplificar cada pixel son 3 enteros. */
	int *_data;

	/* N�mero de pixels, para simplificar todas las im�genes tienen el mismo tama�o. */
	static const unsigned int NUM_PIXELS;
};

