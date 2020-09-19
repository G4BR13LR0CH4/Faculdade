package user;

import empresa.Pedidos;

public class User {
	private String nome;
	private String telefone;
	private Endereco endereco;
	public Pedidos pedido;
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public Endereco getEndereco() {
		return endereco;
	}
	
	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}
	
	public String getTelefone() {
		return telefone;
	}
	
	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}
	
	public void exibeperfil() {
		System.out.println("***** Pefil de usuario: *****");
		System.out.println("Nome: " + nome);
		System.out.println("Telefone: " + telefone);
		endereco.exibirenderco();
	}
	
	public void criarPedido() {
		Pedidos pedido = new Pedidos();
		pedido.setId(1);
		this.pedido = pedido;
	}
	
	
}
