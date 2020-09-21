package empresa;

public class Dinheiro implements Forma_pagamento{
	int valor;
	Pedidos pedido;
	int troco;
	
	public int troco(int valor_pago, int conta) {
		valor(conta);
		this.troco = valor_pago - conta;
		pedido.setStatus("Pedido concluido");
		return troco;
	}

	@Override
	public String tipo(String tipo) {
		return tipo;	
	}

	@Override
	public void valor(int valor) {
		this.valor = valor;
	}

	@Override
	public void pedido(Pedidos aux) {
		this.pedido = aux;
	}
}
