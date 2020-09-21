package empresa;

public class Cartao implements Forma_pagamento{
	int valor;
	Pedidos pedido;
	
	@Override
	public String tipo(String tipo) {
		return tipo;
	}

	@Override
	public void pedido(Pedidos aux) {
		this.pedido = aux;
	}

	@Override
	public void valor(int valor) {
		this.valor = valor;
		pedido.setStatus("Pedido concluido");
		
	}

}
