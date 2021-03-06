package empresa;

import java.util.HashMap;
import java.util.Map;

public class Cardapio {
	
	Map<String, Produto> lista = new HashMap<String, Produto>();
	
	public void addProduto(Produto aux, String index) {
		lista.put(index, aux);
	}
	
	public void removeProduto(String index) {
		Produto aux = buscarProduto(index);
		
		lista.remove(index ,aux);
	}
	
	public Produto buscarProduto(String index) {
		Produto aux = lista.get(index);
		return aux;
	}
	public void exibeLista() {
		System.out.println("---------Cardapio------------");
		for (Produto aux: lista.values()) {
			System.out.println();
			System.out.println("Nome: " + aux.getNome());
			System.out.println("Id: " + aux.getId());
			System.out.println("Ingredientes: " + aux.getIngredientes());
		}
	}
}
