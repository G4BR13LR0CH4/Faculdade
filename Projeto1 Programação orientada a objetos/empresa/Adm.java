package empresa;

public class Adm {
	private String nome;
	private String funcao;
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getFuncao() {
		return funcao;
	}
	
	public void setFuncao(String funcao) {
		this.funcao = funcao;
	}
	
	public void exibeperfil() {
		System.out.println("***** Pefil de Adm: *****");
		System.out.println("Nome: " + nome);
		System.out.println("Função: " + funcao);
	}
	
}
