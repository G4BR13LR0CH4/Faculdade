package empresa;


public interface Forma_pagamento {
	public void pedido(Pedidos aux);
	public String tipo(String tipo);
	public void valor(int valor);
}
