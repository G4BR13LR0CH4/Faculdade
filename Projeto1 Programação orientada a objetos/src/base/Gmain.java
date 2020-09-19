package base;

import java.util.Scanner;

import empresa.Cardapio;
import empresa.Pizza;
import empresa.Produto;
import user.*;


public class Gmain {

	public static void main(String[] args) {
		//Nessa parte eu apenas crio todas as instancias necessarias para o teste.
		//a parte onde código se inicia está marcada
		User user = new User();
		user.setNome("Usuario1");
		user.setTelefone("(xx)xxxxx-xxxx");
		user.criarPedido();
		
		Endereco endereco = new Endereco();
		endereco.setBairro("Bairro teste");
		endereco.setNum_casa(21);
		endereco.setRua("Rua teste");
		
		user.setEndereco(endereco);
		
		Produto sanduba1 = new Produto();
		Produto sanduba2 = new Produto();
		Pizza pizza1 = new Pizza();
		Pizza pizza2 = new Pizza();
		
		sanduba1.setId("01");
		sanduba1.setIngredientes("carne, queijo");
		sanduba1.setNome("sanduba1");
		
		sanduba2.setId("02");
		sanduba2.setIngredientes("carne, ovos, queijo");
		sanduba2.setNome("sanduba2");
		
		pizza1.setId("03");
		pizza1.setIngredientes("carne, presunto,queijo");
		pizza1.setNome("pizza1");
		pizza1.obteminfos("Grande");
		
		pizza2.setId("04");
		pizza2.setIngredientes("carne, bacon, presunto, queijo");
		pizza2.setNome("pizza2");
		pizza2.obteminfos("Medio");
		
		Cardapio cardapio = new Cardapio();
		cardapio.addProduto(sanduba1, sanduba1.getId());
		cardapio.addProduto(sanduba2, sanduba2.getId());
		cardapio.addProduto(pizza1, pizza1.getId());
		cardapio.addProduto(pizza2, pizza2.getId());
		
		//
		
		//Inicio do código
		Scanner input = new Scanner(System.in);
		int op_int, quantidade;
		String id, obs;
		Boolean controle = true;
		
		while(controle ) {
			System.out.println("\n");
			System.out.println("Bem vindo, como você deseja acessar esse serviço?");
			System.out.println("0 - Cliente: ");
			System.out.println("1 - Adm: ");
			System.out.println("2 - Sair: ");
			op_int = input.nextInt();
		
			if(op_int == 0) {
				while(controle) {
					System.out.println("\n");
					System.out.println("Você está logado como --Cliente: " + user.getNome() + "-- ");
					System.out.println("0 - Exibir Perfil:");
					System.out.println("1 - Adicionar item ao carrinho e Verificar cardapio:");
					System.out.println("2 - Fechar pedido e Ver itens do carrinho:");
					System.out.println("3 - Acompanhar pedido:");
					System.out.println("4 - Sair:");
					op_int = input.nextInt();
					
					if(op_int == 0) {
						user.exibeperfil();
					} else if(op_int == 1) {
						cardapio.exibeLista();
						System.out.println("Adicionar produto ao seu carrinho?");
						System.out.println("1 - Sim: ");
						System.out.println("2 - Não: ");
						op_int = input.nextInt();
						
						if(op_int == 1) {
							id = input.nextLine();
							System.out.println("Digite o codigo do produto: ");
							id = input.nextLine();
							System.out.println("Digite a quantidade: ");
							quantidade = input.nextInt();
							obs = input.nextLine();
							System.out.println("Alguma observação?");
							obs = input.nextLine();
							
							user.pedido.carrinho.addCar_item(id, quantidade, obs);
							System.out.println("Produto adicionado com sucesso!");
						}
					} else if(op_int == 2) {
							user.pedido.carrinho.exibeLista();
							System.out.println("Deseja mandar o pedido para loja?");
							System.out.println("1 - Sim: ");
							System.out.println("2 - Não: ");
							op_int = input.nextInt();
							if(op_int == 1)
								user.pedido.setStatus("Pedido esperando confirmação da loja");
							
					} else if(op_int == 3) {
						System.out.println(user.pedido.getStatus());
					} else if(op_int == 4) {
						controle = false;
					} else
						System.out.println("Opção inválida");
				}
				controle = true;
				
			} else if(op_int == 1) {
				System.out.println("Você está logado como --Adm-- ");
			} else if(op_int == 2) {
				controle = false;
			} else
				System.out.println("Opção inválida");
		}
		input.close();
	}

}
