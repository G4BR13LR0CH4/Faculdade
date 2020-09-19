package user;

public class Endereco {
	private String rua;
	private String bairro;
	private int num_casa;
	
	public String getRua() {
		return rua;
	}
	
	public void setRua(String rua) {
		this.rua = rua;
	}
	
	public String getBairro() {
		return bairro;
	}
	
	public void setBairro(String bairro) {
		this.bairro = bairro;
	}
	
	public int getNum_casa() {
		return num_casa;
	}
	
	public void setNum_casa(int num) {
		this.num_casa = num;
	}
	
	public void exibirenderco() {
		System.out.println("Bairro: " + bairro);
		System.out.println("Rua: " + rua);
		System.out.println("Numero da casa: " + num_casa);
	}
}
