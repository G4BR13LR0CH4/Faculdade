package user;

import java.util.Set;
import java.util.HashSet;

public class Carrinho {
	Set<Car_item> lista = new HashSet<Car_item>();
	
	public void addCar_item(String id, int quantidade, String obs) {
		Car_item aux = new Car_item();
		aux.id = id;
		aux.quantidade = quantidade;
		aux.obs = obs;
		lista.add(aux);
	}
	
	public void addCar_item(String id, int quantidade, String obs, String tam) {
		Car_item aux = new Car_item();
		aux.id = id;
		aux.quantidade = quantidade;
		aux.obs = obs;
		aux.tam = tam;
		lista.add(aux);
	}
	public void removeCar_item(Car_item aux) {
		lista.remove(aux);
	}
	
	public void exibeLista() {
		for (Car_item aux: lista) {
			System.out.println("***** Produtos no carrinho: *****");
			System.out.println();
			System.out.println("Id: " + aux.id);
			System.out.println("Quantidade:" + aux.quantidade);
			System.out.println("Observações: " + aux.obs);
			
			if(aux.tam != null) 
				System.out.println("Tamanho: " + aux.tam);
			
		}
	}
}
