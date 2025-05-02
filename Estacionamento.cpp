#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<list>
#include<fstream>
using namespace std;

class Carro
{
	private:
		string placa, tipo;
	public:
		Carro()
		{
			placa = "nao informado ";
			tipo = "nao informado ";
		}
		~Carro()
		{
		}
		void set_dados()
		{
			cout << "\nDigite a placa do carro: ";
			getline(cin>>ws, placa);
			cout << "\nDigite o tipo de carro: (comum /prioritario / emergencia / servico) ";
			getline(cin>>ws, tipo);
		}
		void print_dados()
		{
			cout << "\n " << placa << "\t " << tipo;
		}
		string ret_placa()
		{
			return placa;
		}
		string ret_tipo()
		{
			return tipo;
		}
};

int main()
{
	queue<Carro> entrada, ent_aux1, ent_aux2;
	deque<Carro> saida, sai_aux1;
	Carro temp;
	string resp, consulta, portao;
	int op, pos;
	list<Carro> estacionamento, est_aux1;
	vector<bool> vagas(11,false);
	ofstream historico;
	do
	{
		historico.open("historico.txt");
		system("cls");
		cout << "\n==========================================================================================================";
		cout << "\n\t\tEstacionamento";
		cout << "\n==========================================================================================================";
		cout << "\n\n\t< 1 > Inserir carro na fila de entrada ";
		cout << "\n\t< 2 > Estacionar ";
		cout << "\n\t< 3 > Inserir carro na fila de saida ";
		cout << "\n\t< 4 > Listar carros na fila de entrada ";
		cout << "\n\t< 5 > Listar carros no estacionamento ";
		cout << "\n\t< 6 > Listar carros na fila de saida ";
		cout << "\n\t< 7 > Sair ";
		cout << "\n";
		cout << "\n==========================================================================================================";
		cout << "\nDigite a sua opcao -> [ ] \b\b\b";
		cin >> op;
		historico << "\nOpcao " << op << " selecionada ";
		switch (op)
		{
			case 1:
				do
				{
					system("cls");
					cout << "\n==========================================================================================================";
					cout << "\n\t\tEstacionamento - INSERIR CARRO NA FILA DE ENTRADA ";
					cout << "\n==========================================================================================================";
					temp.set_dados();
					ent_aux1.push(temp);
					historico << "\nInserido carro " << temp.ret_placa() << " " << temp.ret_tipo() << " na fila de entrada ";
					cout << "\nDeseja inserir outro carro na fila de entrada? (sim/nao) ";
					getline(cin>>ws,resp);
				}while (resp=="sim");
				while(!ent_aux1.empty())
				{
					if(ent_aux1.front().ret_tipo() == "emergencia")
					{
						entrada.push(ent_aux1.front());
						ent_aux1.pop();
						historico << "\nCarro de emergencia priorizado ";
					}
					else 
					{
						ent_aux2.push(ent_aux1.front());
						ent_aux1.pop();
					}
				}
				while(!ent_aux2.empty())
				{
					if(ent_aux2.front().ret_tipo() == "prioritario")
					{
						entrada.push(ent_aux2.front());
						ent_aux2.pop();
						historico << "\nCarro prioritario priorizado ";
					}
					else 
					{
						ent_aux1.push(ent_aux2.front());
						ent_aux2.pop();
					}
				}
				while(!ent_aux1.empty())
				{
					entrada.push(ent_aux1.front());
					ent_aux1.pop();
				}
				cout << "\nCarro inserido na fila de entrada! ";
			break;
			case 2:
				do
					{
						system("cls");
						cout << "\n==========================================================================================================";
						cout << "\n\t\tEstacionamento - ESTACIONAR ";
						cout << "\n==========================================================================================================";
						cout << "\nVAGAS DISPONIVEIS: \n";
						for (int a = 1; a < vagas.size(); a++)
						{
							if(!vagas[a])
							{
							cout << a << "  ";
							}
						}
						if(entrada.empty())
						{
							cout << "\nSem carros na fila para estacionar \n ";
							resp = "nao";
							historico << "\nSem carros para estacionar ";
						}
						else
						{
							cout << "\nDigite a vaga que deseja estacionar: ";
							cin >> pos;
							if (pos >= 1 && pos < vagas.size()) 
							{
							    if (!vagas[pos]) 
								{
							        vagas[pos] = true;
							        estacionamento.push_back(entrada.front());
							        historico << "\nInserido carro " << entrada.front().ret_placa() << " na vaga " << pos;
							        entrada.pop();
							        cout << "\nCarro estacionado na vaga " << pos << " com sucesso!\n";
							    }
								else 
								{
							        cout << "\nVaga ocupada!\n";
							        historico << "\nVaga digitada ocupada ";
							    }
							}
							else
							{
						    	cout << "\nVaga invalida!\n";
						    	historico << "\Vaga digitada invalida ";
						    }
						cout << "\nDeseja inserir outro carro no estacionamento? (sim/nao) ";
						getline(cin>>ws,resp);
						}
					}while (resp=="sim");
			break;
			case 3: /*
				do
				{
					system("cls");
					cout << "\n==========================================================================================================";
					cout << "\n\t\tEstacionamento - INSERIR CARRO NA FILA DE SAIDA ";
					cout << "\n==========================================================================================================";
					cout << "\nDigite a placa do carro que deseja inserir na fila de saida: ";
					getline(cin>>ws, consulta);
					cout << "\nDeseja sair pela frente ou por tras? ";
					getline(cin>>ws, portao);
					if (portao == "frente")
					{
						saida.push_front(estacionamento.)
					}
					cout << "\Deseja inserir outro carro na fila de saida? (sim/nao) ";
					getline(cin>>ws,resp);
				}while (resp=="sim"); */
			break;
			case 4:
				system("cls");
				cout << "\n==========================================================================================================";
				cout << "\n\t\tEstacionamento - LISTA DE CARROS NA FILA DE ENTRADA ";
				cout << "\n==========================================================================================================";
				ent_aux1 = entrada;
				while(!ent_aux1.empty())
				{
					ent_aux1.front().print_dados();
					ent_aux1.pop();
				}
				historico << "\nLista de carros na fila de entrada impressa ";
			break;
			case 5:
				system("cls");
				cout << "\n==========================================================================================================";
				cout << "\n\t\tEstacionamento - LISTA DE CARROS NO ESTACIONAMETO ";
				cout << "\n==========================================================================================================";
				est_aux1 = estacionamento;
				while(!est_aux1.empty())
				{
					est_aux1.front().print_dados();
					est_aux1.pop_front();
				}
				historico << "\nLista de carros no estacionamento impressa ";
			break;
			case 6:
				system("cls");
				cout << "\n==========================================================================================================";
				cout << "\n\t\tEstacionamento - LISTA DE CARROS NA FILA DE SAIDA ";
				cout << "\n==========================================================================================================";
				sai_aux1 = saida;
				while(!sai_aux1.empty())
				{
					sai_aux1.front().print_dados();
					sai_aux1.pop_front();
				}
				historico << "\nLista de carros na fila de saida impressa ";
			break;
			case 7:
				historico << "\nPrograma finalizado ";
				historico.close();
				exit(0);
			break;
			default:
		        system("cls");
				cout << "\n==========================================================================================================";
				cout << "\n\t\tOPCAO INVALIDA!!!! ";
				cout << "\n==========================================================================================================";
				historico << "\nOpcao invalida digitada no menu ";
	      	break;
		}
	cout << "\nDeseja voltar para o menu principal? (sim/nao) ";
    cin >> resp;
    }while(resp == "sim"); 
	historico.close(); 
	return 0;
}
