#include <stdio.h>
#include <stdlib.h>

int a = -1;
int b = -1;
int u_l = -1;
int idfun;			// identificador (esqueci para que serve)



  typedef struct
  {				// endereC'o para funcionario
    char rua[30];
    int num;
    char bairro[17];
    int cep;
  } Endereco;

  typedef struct
  {				// cadastro de funcionario
    char nome[50];
    int idade; 
    int telefone;
    int cpf;
    char email[50];
    int identificacao;
    float salario;
    Endereco endereco[140];
  } Cadastro;

  Cadastro cadastroFuncionario[140];

  void cadastrarFuncionario ()
  {				// funcao para cadastrar funcionario
    a++;
    b++;
    idfun = a;
    u_l = idfun;
    printf
      ("-----------------CADASTRO FUNCIONARIO----------------\n->DADOS PESSOAIS:\n");
    scanf ("%*c");
    printf ("Nome: ");
    fflush (stdin);
    fgets (cadastroFuncionario[u_l].nome, 45, stdin);
    printf ("Idade: ");
    scanf ("%d", &cadastroFuncionario[u_l].idade);
    printf ("Telefone: ");
    scanf ("%d", &cadastroFuncionario[u_l].telefone);
    printf ("CPF(somente numeros): ");
    scanf ("%d", &cadastroFuncionario[u_l].cpf);
    printf ("E-mail: ");
    scanf ("%*c");
    fflush (stdin);
    fgets (cadastroFuncionario[u_l].email, 45, stdin);
    printf ("\n->ENDERECO:\n");
    printf ("Rua: ");
    fflush (stdin);
    fgets (cadastroFuncionario[u_l].endereco[b].rua, 25, stdin);
    printf ("Numero: ");
    scanf ("%d", &cadastroFuncionario[u_l].endereco[b].num);
    printf ("Bairro: ");
    scanf ("%*c");
    fflush (stdin);
    fgets (cadastroFuncionario[u_l].endereco[b].bairro, 12, stdin);
    printf ("CEP: ");
    scanf ("%d", &cadastroFuncionario[u_l].endereco[b].cep);

    while (cadastroFuncionario[u_l].idade < 18)
      {
	printf ("\nIdade Invalida! Apenas +18!\nINFORME NOVAMENTE:\n");
	printf ("Idade: ");
	scanf ("%d", &cadastroFuncionario[u_l].idade);
	system ("clear");
      }
    printf ("-------------CADASTRO FINALIZADO--------------\n");
    printf ("\nSeu numero de identificao e: %d\n", u_l);
    printf ("-----------------------------------------------\n");
    cadastroFuncionario[u_l].identificacao = u_l;
  }

  int buscarPosicaoFuncionario (int id)
  {				// buscar posicao do funcionario
    for (int i = 0; i <= u_l && i <= b; i++)
      {
	if (cadastroFuncionario[i].identificacao == id)
	  {
	    return i;
	  }
      }
    return -1;
  }

  void pesquisarFuncionario ()
  {				// pesquisar o funcionario
    int id;
    printf ("Digite o ID: ");
    scanf ("%d", &id);
    int pos = buscarPosicaoFuncionario (id);
    if (pos != -1)
      {
	printf ("\nENCONTRADO(A)!\n==>INFORMACOES:\n");
	printf ("NUMERO ID: %d\nNOME: %s\nIDADE: %d\n",
		cadastroFuncionario[pos].identificacao,
		cadastroFuncionario[pos].nome,
		cadastroFuncionario[pos].idade);
	printf ("TELEFONE: %d\nCPF: %d\nE-MAIL: %s",
		cadastroFuncionario[pos].telefone,
		cadastroFuncionario[pos].cpf, cadastroFuncionario[pos].email);
	printf ("\nENDERECO: %s\nNUMERO: %d\nBAIRRO: %s\nCEP: %d\n",
		cadastroFuncionario[pos].endereco[b].rua,
		cadastroFuncionario[pos].endereco[b].num,
		cadastroFuncionario[pos].endereco[b].bairro,
		cadastroFuncionario[pos].endereco[b].cep);
      }
    else
      {
	printf ("\nNAO FOI ENCONTRADO(A)!\n");
      }
  }

  void realizarCheckIn ()
  {				// check-in do funcionario
    int id, res;
    printf ("Digite o ID: ");
    scanf ("%d", &id);
    int pos = buscarPosicaoFuncionario (id);
    if (pos != -1)
      {
	float diasTrabalhados;
	diasTrabalhados++;
	cadastroFuncionario[pos].salario += diasTrabalhados * 30;	// salario = 30 reais por dia
	printf ("\nCheck-in realizado com sucesso!\n");
	if (diasTrabalhados==30)
	    {
	printf("\nVOCE TEM UM SALARIO DISOINIVEL NO VALOR DE R$ %2.f. \n", cadastroFuncionario[pos].salario);
	printf("retirar?\n[1]-SIM\n[2]-NAO\n");
	scanf("%d", &res);
	if (res == 1)
	    {
	cadastroFuncionario[pos].salario = 0;
	printf ("Retirado!!!");
	    }
	else if (res == 2)
	    {
	printf("ok!");   
	    }
	else
	    {
	printf("opcao invalida!");   
	    }
	    }
	   }
    else
      {
	printf ("\nFuncionC!rio nao encontrado!\n");
      }
  }

  void listarFuncionarios ()
  {				// listar todos os funcionarios
    printf ("\nFUNCIONARIOS CADASTRADOS:\n");
    for (int i = 0; i <= u_l && i <= b; i++)
      {
	printf ("\n==>ID: %d\nNOME: %s\nIDADE: %d\n",
		cadastroFuncionario[i].identificacao,
		cadastroFuncionario[i].nome, cadastroFuncionario[i].idade);
	printf ("TELEFONE: %d\nCPF: %d\nE-MAIL: %s",
		cadastroFuncionario[i].telefone, cadastroFuncionario[i].cpf,
		cadastroFuncionario[i].email);
	printf ("\nENDERECO: %s\nNUMERO: %d\nBAIRRO: %s\nCEP: %d\n",
		cadastroFuncionario[i].endereco[b].rua,
		cadastroFuncionario[i].endereco[b].num,
		cadastroFuncionario[i].endereco[b].bairro,
		cadastroFuncionario[i].endereco[b].cep);
      }
  }

  void alterarDadosFuncionario ()
  {				// alterar dados do funcionario
    int id;
    printf ("Digite o ID: ");
    scanf ("%d", &id);
    int pos = buscarPosicaoFuncionario (id);
    if (pos != -1)
      {
	printf ("\n==>INFORMACOES ATUAIS:\n");
	printf ("NUMERO ID: %d\nNOME: %s\nIDADE: %d\n",
		cadastroFuncionario[pos].identificacao,
		cadastroFuncionario[pos].nome,
		cadastroFuncionario[pos].idade);
	printf ("TELEFONE: %d\nCPF: %d\nE-MAIL: %s",
		cadastroFuncionario[pos].telefone,
		cadastroFuncionario[pos].cpf, cadastroFuncionario[pos].email);
	printf ("\nENDERECO: %s\nNUMERO: %d\nBAIRRO: %s\nCEP: %d\n",
		cadastroFuncionario[pos].endereco[b].rua,
		cadastroFuncionario[pos].endereco[b].num,
		cadastroFuncionario[pos].endereco[b].bairro,
		cadastroFuncionario[pos].endereco[b].cep);
	printf ("\n==>NOVAS INFORMACOES:\n");
	printf ("Nome: ");
	scanf ("%*c");
	fflush (stdin);
	fgets (cadastroFuncionario[pos].nome, 45, stdin);
	printf ("Idade: ");
	scanf ("%d", &cadastroFuncionario[pos].idade);
	printf ("Telefone: ");
	scanf ("%d", &cadastroFuncionario[pos].telefone);
	printf ("CPF: ");
	scanf ("%d", &cadastroFuncionario[pos].cpf);
	printf ("E-mail: ");
	scanf ("%*c");
	fflush (stdin);
	fgets (cadastroFuncionario[pos].email, 45, stdin);
	printf ("\n->ENDERECO:\n");
	printf ("Rua: ");
	fflush (stdin);
	fgets (cadastroFuncionario[pos].endereco[b].rua, 25, stdin);
	printf ("NC:mero: ");
	scanf ("%d", &cadastroFuncionario[pos].endereco[b].num);
	printf ("Bairro: ");
	scanf ("%*c");
	fflush (stdin);
	fgets (cadastroFuncionario[pos].endereco[b].bairro, 12, stdin);
	printf ("CEP: ");
	scanf ("%d", &cadastroFuncionario[pos].endereco[b].cep);
	printf ("\nAlteracoes realizadas com sucesso!\n");
      }
    else
      {
	printf ("\nFuncionario nao encontrado!\n");
      }
  }

  void removerFuncionario ()
  {				// remover funcionC!rio do cadastro
    int id;
    printf ("Digite o ID: ");
    scanf ("%d", &id);
    int pos = buscarPosicaoFuncionario (id);
    if (pos != -1)
      {
	for (int i = pos; i <= u_l; i++)
	  {
	    cadastroFuncionario[i] = cadastroFuncionario[i + 1];
	  }
	u_l--;
	b--;
	printf ("\nFuncionario removido com sucesso!\n");
      }
    else
      {
	printf ("\nFuncionario nao encontrado!\n");
      }
  }

  void menuFuncionarios()//menu principal pra funcionario
  {
    int opcao;
    do
      {
	printf
	  ("\n-----------SISTEMA DE FUNCIONARIOS-----------\n");
	printf ("1 - Cadastrar funcionario\n");
	printf ("2 - Pesquisar funcionario\n");
	printf ("3 - Realizar check-in\n");
	printf ("4 - Listar funcionarios cadastrados\n");
	printf ("5 - Alterar dados do funcionario\n");
	printf ("6 - Remover funcionario\n");
	printf ("0 - Sair\n");
	printf ("--------------------------------------------------------\n");
	printf ("Escolha uma opcao: ");
	scanf ("%d", &opcao);
	system ("clear");
	switch (opcao)
	  {
	  case 1:
	    cadastrarFuncionario ();
	    break;
	  case 2:
	    pesquisarFuncionario ();
	    break;
	  case 3:
	    realizarCheckIn ();
	    break;
	  case 4:
	    listarFuncionarios ();
	    break;
	  case 5:
	    alterarDadosFuncionario ();
	    break;
	  case 6:
	    removerFuncionario ();
	    break;
	  case 0:
	    printf ("\nSaindo...\n");
	    break;
	  default:
	    printf ("\nOpcao invalida!\n");
	    break;
	  }
      }
    while (opcao != 0);
      
  }

typedef struct
{				//endereco para cliente
  char rua2[30];
  int num2;
  char bairro2[17];
  int cep2;
} Endereco2;

typedef struct
{				//cadastro para cliente
  char nome2[50];
  int idd2, tel2, cpf2;
  char email2[50];
  int iden2;
  float salario2;
  Endereco2 endfun2[140];
} Cadastro2;

Cadastro2 cad2[140];

void
Cadstr2 ()
{				//void para cadastrar o cliente
  a++;
  b++;
  idfun = a;
  u_l = idfun;
  printf
    ("-----------------CADASTRO CLIENTE----------------\n->DADOS PESSOAIS:\n");
  scanf ("%*c");
  printf ("Nome: ");
  fflush (stdin);
  fgets (cad2[u_l].nome2, 45, stdin);
  printf ("Idade: ");
  scanf ("%d", &cad2[u_l].idd2);
  printf ("Telefone: ");
  scanf ("%d", &cad2[u_l].tel2);
  printf ("CPF: ");
  scanf ("%d", &cad2[u_l].cpf2);
  printf ("E-mail: ");
  scanf ("%*c");
  fflush (stdin);
  fgets (cad2[u_l].email2, 45, stdin);
  printf ("\n->ENDERECO:\n");
  printf ("Rua: ");
  fflush (stdin);
  fgets (cad2[u_l].endfun2[b].rua2, 25, stdin);
  printf ("Numero: ");
  scanf ("%d", &cad2[u_l].endfun2[b].num2);
  printf ("Bairro: ");
  scanf ("%*c");
  fflush (stdin);
  fgets (cad2[u_l].endfun2[b].bairro2, 12, stdin);
  printf ("CEP: ");
  scanf ("%d", &cad2[u_l].endfun2[b].cep2);

  while (cad2[u_l].idd2 < 18)
    {
      printf ("\nIdade InvC!lida! Apenas +18!\nINFORME NOVAMENTE:\n");
      printf ("Idade: ");
      scanf ("%d", &cad2[u_l].idd2);
      system ("clear");
    }
  printf ("-------------CADASTRO FINALIZADO--------------\n");
  printf ("\nSeu nC:mero de identificaC'C#o C): %d\n", u_l);
  printf ("-----------------------------------------------\n");
  cad2[u_l].iden2 = u_l;
}

int
bscr_psc2 (int id2)
{				//buscar posicao do cliente
  for (int i = 0; i <= u_l && i <= b; i++)
    {
      if (cad2[i].iden2 == id2)
	{
	  return i;
	}
    }
  return -1;
}

void
Pesquisa2 ()
{				//pesquisar cliente
  int id2;
  printf ("Digite o ID: ");
  scanf ("%d", &id2);
  int pos2 = bscr_psc2 (id2);
  if (pos2 != -1)
    {
      printf ("\nCLIENTE ENCONTRADO(A)!\n==>INFORMACOES:\n");
      printf ("NUMERO ID: %d\nNOME: %s\nIDADE: %d\n", cad2[pos2].iden2,
	      cad2[pos2].nome2, cad2[pos2].idd2);
      printf ("TELEFONE: %d\nCPF: %d\n", cad2[pos2].tel2, cad2[pos2].cpf2);
      printf ("E-MAIL: %s\n", cad2[pos2].email2);
      printf ("ENDERECO: Rua %s, NB0%d, Bairro %s,-%d-",
	      cad2[pos2].endfun2[pos2].rua2, cad2[pos2].endfun2[pos2].num2,
	      cad2[pos2].endfun2[pos2].bairro2,
	      cad2[pos2].endfun2[pos2].cep2);
    }
  else
    {
      printf ("NC#o encontrado!\n");
    }
}


void
listarr2 ()
{				//listar quantidade de clientes
if (u_l>=0){
  printf ("\n=============LISTA-CLIENTES=============\n");
  for (int i = 0; i <= u_l; i++)
    {
      printf ("\n");
      printf ("ID: %d", cad2[i].iden2);
      printf ("NOME: %s \n", cad2[i].nome2);
      printf ("__________________________________\n");
    }
}else{
    printf("\nnão ha clientes cadastrados\n");
}
}

void
alterardados2 ()
{				//alterar dados do cliente
  int id2;
  printf ("\n=====-ALTERAR DADOS=====\n");
  printf ("Digite o ID:");
  scanf ("%d", &id2);
  printf ("\n========================\n");
  int pos2 = bscr_psc2 (id2);
  int resp;
  printf ("[1]-E-MAIL\n[2]-TELEFONE\n[3]-ENDERECO\n");
  scanf ("%d", &resp);
  if (pos2 != -1)
    {
      switch (resp)
	{
	case 1:
	  printf ("NOVO E-MAIL: ");
	  scanf ("%*c");
	  fflush (stdin);
	  fgets (cad2[pos2].email2, 45, stdin);
	case 2:
	  printf ("NOVO TELEFONE: ");
	  scanf ("%d", &cad2[u_l].tel2);
	case 3:
	  printf ("NOVO ENDERECO:\n");
	  printf ("Rua: ");
	  fflush (stdin);
	  fgets (cad2[pos2].endfun2[pos2].rua2, 25, stdin);
	  printf ("Numero: ");
	  scanf ("%d", &cad2[pos2].endfun2[pos2].num2);
	  printf ("Bairro: ");
	  scanf ("%*c");
	  fflush (stdin);
	  fgets (cad2[pos2].endfun2[pos2].bairro2, 12, stdin);
	  printf ("CEP: ");
	  scanf ("%d", &cad2[pos2].endfun2[pos2].cep2);
	}
    }
  else
    {
      printf ("Nao encontrado!\n");
    }
}
void removerCliente ()
  {				// remover clente do cadastro
    int id2;
    printf ("Digite o ID: ");
    scanf ("%d", &id2);
    int pos2 = bscr_psc2 (id2);
    if (pos2 != -1)
      {
	for (int i = pos2; i <= u_l; i++)
	  {
	    cad2[i] = cad2[i + 1];
	  }
	u_l--;
	b--;
	printf ("\nFuncionC!rio removido com sucesso!\n");
      }
    else
      {
	printf ("\nFuncionC!rio nC#o encontrado!\n");
      }
}

void produtos(){
    int sna;
    float resposta, valor, vl_f;
    do
	    {
	      printf ("\n======>>PRODUTOS:\n");
	      printf
		("1-RACAO.........R$ 3,00 KG\n2-ACESSORIOS.......R$ 20,00\n3-CASINHAS.........R$ 150,00\n4-CAMINHAS........R$ 80,OO\n[0]-SAIR\n");
	      scanf ("%d", &sna);
	      switch (sna)
		{
		case 1:
		  printf ("Quantos quilos de de raC'ao deseja? ");
		  scanf ("%f", &resposta);
		  valor = resposta * 3.00;
		  break;
		case 2:
		  printf ("Quantidade de acessorios: ");
		  scanf ("%f", &resposta);
		  valor = resposta * 20.00;
		  break;
		case 3:
		  printf ("Quantidade de casinhas: ");
		  scanf ("%f", &resposta);
		  valor = resposta * 150.00;
		  break;
		case 4:
		  printf ("Quantidade de caminhas: ");
		  scanf ("%f", &resposta);
		  valor = resposta * 80.00;
		  break;
		}
	      vl_f = vl_f + valor;
	    }
	  while (sna != 0);
	  printf ("Sua compra saiu no valor de R$ %2.f.", vl_f);
}

void animal(){
    int sna, rrep;
    char nm_anml[10];
    char raca[10];
    int porte, tipo;
    float resposta, valor, vl_f;
    do
	    {
	      printf ("\n======>>ANIMAL:\n");
	      printf ("\n---Dados do animal---\n");
	      printf ("Nome: ");
	      fflush (stdin);
	      fgets (nm_anml, 7, stdin);
	      scanf ("%*c");
	      printf ("Raca: ");
	      fflush (stdin);
	      fgets (raca, 7, stdin);
	      scanf ("%*c");
	      printf
		("\nEle C):\n[1]-PEQUENO PORTE;\n[2]-MEDIO PORTE;\n[3]-GRANDE PORTE.\n");
	      scanf ("%d", &porte);
	      if (porte == 1)
		{
		  valor = 100.0;
		}
	      else if (porte == 2)
		{
		  valor = 200.0;
		}
	      else if (porte == 3)
		{
		  valor = 350.0;
		}
	      else
		{
		  printf ("\nOpcao InvC!lida.\n");
		}
	      printf ("\n-----------------\n");
	      printf ("1-BANHO\n2-TOSA\n3-COMBO(BANHO+TOSA)\n[0]-SAIR\n");
	      scanf ("%d", &sna);
	      switch (sna)
		{
		case 1:
		  printf ("BANHO.....R$ 100,00\n");
		  vl_f = valor + 100.00;
		  break;
		case 2:
		  printf
		    ("TOSA:\n[1]SIMPLES.....R$ 75,00\n[2]-COMPLETA.....R$ 85,00\n");
		  scanf ("%f", &resposta);
		  if (resposta == 1)
		    {
		      vl_f = valor + 75.0;
		    }
		  else if (resposta == 2)
		    {
		      vl_f = valor + 85.0;
		    }
		  else
		    {
		      printf ("opcao invalida.");
		    }
		  break;
		case 3:
		  printf
		    ("COMBO:\n[1]SIMPLES.....R$ 170,00\n[2]-COMPLETA.....R$ 182,00\n");
		  scanf ("%f", &resposta);
		  if (resposta == 1)
		    {
		      vl_f = valor + 170.0;
		    }
		  else if (resposta == 2)
		    {
		      vl_f = valor + 182.0;
		    }
		  else
		    {
		      printf ("opcao invalida.");
		    }
		  break;
		}
	      printf ("\nIcluir acessorios(R$20)? [1]-SIM [2]-NAO\n");
	      scanf ("%d", &rrep);
	      if (rrep == 1)
		{
		  vl_f = vl_f + 20.0;
		}
	      else
		{
		  break;
		}
	      printf ("\nTransporte para o animal(R$10)? [1]-SIM [2]-NAO\n");
	      scanf ("%d", &rrep);
	      if (rrep == 1)
		{
		  vl_f = vl_f + 10.0;
		}
	      else
		{
		  break;
		}
	      printf ("\nValor final R$ %2.f\n", vl_f);
	    }
	  while (sna != 0);
	}
    



void
Servicos ()
{				//servicos do petshop
  int ans, sna, rrep;
  float resposta, valor, vl_f;
  char nm_anml[10];
  char raca[10];
  int porte, tipo;
  int id2;
  for(int i=0; i <=u_l; i++){
      printf ("Digite o ID: ");
      scanf ("%d", &id2);
      if (id2==i){
          int pos2 = bscr_psc2 (id2);
          printf ("ola %s!\n", cad2[pos2].nome2);
          do
            {
              printf ("\n===============SERVICOS===============\n");
              printf ("[1]-PRODUTOS\n[2]-CUIDADOS COM O ANIMAL\n[0]-SAIR\n");
              scanf ("%d", &ans);
              switch (ans)
        	{
        	case 1:
        	  produtos();
        	  break;
        	case 2:
        	  animal();
        	  break;
        	}
            }
          while (ans != 0);
      }else{
          printf("Cliente nao encontrado");
      }
  }
}


void menuClientes(){
    int op2;
    do{
       printf("\n------------SISTEMA DE CLIENTES------------\n");
       printf("[1]-CADASTRAR CLIENTE\n");
       printf("[2]-PESQUISAR CLIENTE\n");
       printf("[3]-SERVICOS DO PET SHOP\n");
       printf("[4]-LISTAR CLIENTES\n");
       printf("[5]-ALTERAR DADOS DO CLIENTE\n");
       printf("[6]-REMOVER CLIENTE\n");
       printf("[0]-SAIR\n");
       printf("Opcao: ");
	   scanf ("%d", &op2);
	   printf ("\n-------------------------------\n");
	   switch (op2){
	       case 1:
	           Cadstr2();
	           break;
	       case 2:
	           Pesquisa2();
	           break;
	       case 3:
	           Servicos();
	           break;
	       case 4:
	           listarr2();
	           break;
	       case 5:
	           alterardados2();
	           break;
	       case 6:
	           removerCliente();
	           break;
	       case 0:
	           printf ("\nSaindo...\n");
	           break;
	       default:
	           printf ("\nOpcao invalida!\n");
	           break;
	  }
    }
    while (op2 != 0);
}

int
main ()
{
  int res, senha1;
  int op, op2, op3;
  int senha = 1234;
  printf ("====================PET SHOP======================\n");
  do
    {
      printf
	("\n[1]-FUNCIONARIO\n[2]-CLIENTE\n[3]-SAIR\nOpcao: ");
      scanf ("%d", &op);
      printf ("===========================\n");
      switch (op)
	{
	case 1:
	  printf ("Senha: ");
	  scanf ("%d", &senha1);
	  if (senha1 == senha)
	    {
	      printf ("\nacesso permitido\n");
	      menuFuncionarios ();
	    }
	  else
	    {
	      printf ("\nacesso negado\n");
	      break;
	    }
	  break;
	case 2:
        menuClientes();
		break;  
	}
    }
  while (op != 3);

  return 0;
}
