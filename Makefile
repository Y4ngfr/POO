OUTPUT := sistema.out

all: 
	@ g++ main.cpp Veiculos/* Pedidos/* Clientes/* Carros/* Motos/* Caminhao/* ListaVeiculos/* Logistica/* GeoShell/*pp AlimentadorBancoDados/* Sistema/* -g -o $(OUTPUT) -fopenmp -lpthread