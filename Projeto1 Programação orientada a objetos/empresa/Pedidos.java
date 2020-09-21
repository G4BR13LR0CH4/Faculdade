package empresa;

import user.Carrinho;

public class Pedidos {
	private int id;
	public Carrinho carrinho = new Carrinho();
	private String status = "Status: Em andamento";
	
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
	
	public String forma_pagamento(int valor) {
		if(valor == 1)
			return "Cartão";
		else if(valor == 2)
			return "Dinheiro";
		
		return "";
	}
}
