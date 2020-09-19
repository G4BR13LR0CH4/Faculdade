package empresa;

import user.Carrinho;

public class Pedidos {
	int id;
	public Carrinho carrinho = new Carrinho();
	String status = "Status: Em andamento";
	
	public int getId() {
		return id;
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public String getStatus() {
		return status;
	}
	
	public void setStatus(String status) {
		this.status = status;
	}
}
