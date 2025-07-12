---
tags:
  - cpp
links: 
aliases:
  - encapsulation
---
# Kapselung
>Bündeln von Daten(Attribute und Methoden), die auf einer bestimmten Einheit(meist `class`) agieren
# Code Beispiele/Aufgaben
## C - Ohne Kapselung
```c
typedef struct vector2d {
	double *v;
} vector2d;

void vector2d_init(vector2d* vec, double x, double y) {
	vec->v = malloc(2*sizeof(double));
	vec->v[0] = x; vec->v[1] = y;
}

void vector2d_destroy(vector2d* vec) {
	free(vec->v);
}

double vector2d_get_x(vector2d* vec) {
	return vec->v[0]; 
}

double vector2d_get_y(vector2d* vec) {
	return vec->v[1]; 
}

void vector2d_print(vector2d* vec) {
	printf("(%f,%f)\n", vector2d_get_x(vec),
	vector2d_get_y(vec));
}

int main() {
	vector2d vec; vector2d_init(&vec, 1.0, 2.0);
	vector2d_print(&vec);
	vector2d_destroy(&vec);
}
```
## C++ - Mit Kapselung
```cpp
struct vector2d {
	double *v;
	
	void init(double x, double y) {
		v = new double[]{x, y};
	}

	void destroy() {
		delete[] v;
	}
	
	double x() {
		return v[0];
	}

	double y() {
		return this->v[1];
	}

	void print() {
		cout << "(" << x() << "," <<
		this->y() << ")" << endl;
	}
};

int main() {
	vector2d vec; vec.init(1.0, 2.0);
	vec.print();
	vec.destroy();
}
```
- [[0503 Konstruktoren und Destruktoren#Code Beispiele/Aufgaben]] for full conversion to using C++ features
# Flashcards
