/******************************************************************************

                        	Stephanie Mendes

*******************************************************************************/
#include <utility>      // std::pair, std::make_pair
#include <iostream>
#include <queue> // biblioteca padrao c++ para fila 
#include <string.h> //clear
#include <math.h> 
#include <time.h>       // para calcular o tempo de execuação                	
using namespace std;


  bool DFS(int i, int j);
  void BFS(int i, int j);
  bool verifica(int i, int j);
  void Best(int i,int j);
  char caminho[100][100];
  bool status [100][100];
  bool achou;
  int n,m,fimi,fimj,imprime;
  clock_t tempo;
  

int main(){

    // achou tem q ser global??
    
    int i,j,posi,posj, op;
    
    
    
    achou=false;
    
    cout << "Digite  1 para inserir uma nova  ou 2 para executar o labirinto do pdf \n";
    cin >> op;
    
    if (op == 1) {
        
         cout<<"Digite o tamanho da linha da matriz \n";
         cin >> n ;
         cout<<"Digite o tamanho da coluna da matriz \n";
         cin >> m ;
         for(i=0;i<n;i++){
     	    for(j=0;j<m;j++){
     	    
                cout << "Digite o elemento da pos" <<i+1 <<" " << j+1 << endl;
         		cin >> caminho[i][j]; 
         		status[i][j]= false; // inicializa posicoes com falso, ou seja nao visitado
         		if (caminho[i][j]=='#'){
         		        posi=i; // guarda pos inicial referente #
         		        posj=j; // guarda pos inicial referente #
     	    	}
     	    	if (caminho[i][j]=='$'){
         		        fimi=i; // guarda pos inicial referente #
         		        fimj=j; // guarda pos inicial referente #
     	    	}
        	}
         }
        
    }else{
        n=13;
        m=15;
        
         // colocar todas as pos com o valor *
         for(i=0;i<n;i++){
     	    for(j=0;j<m;j++){
     	    
                caminho[i][j]= '*'; 
     		    status[i][j]= false; // inicializa posicoes com falso, ou seja nao visitado

     	    }
         }
         
             
         // inserir detalhes do labirinto
         posi=0; // guarda pos inicial referente #
         posj=3; // guarda pos inicial referente #

         fimi=11; // guarda pos final referente $
         fimj=12; // guarda pos final referente $
    
         caminho[0][3]= '#';
         caminho[2][0]= '-';
         caminho[2][1]= '-';
         caminho[2][2]= '-';
         caminho[2][3]= '-';
         caminho[2][4]= '-';
         caminho[2][5]= '-';
         caminho[2][6]= '-';
         caminho[2][7]= '-';
         caminho[2][8]= '-';
         caminho[2][9]= '-';
         caminho[2][10]= '-';
         caminho[2][11]= '-';
         caminho[2][12]= '-';
         caminho[7][2]= '-';
         caminho[8][2]= '-';
         caminho[9][2]= '-';
         caminho[9][7]= '-';
         caminho[9][8]= '-';
         caminho[9][9]= '-';
         caminho[9][10]= '-';
         caminho[9][11]= '-';
         caminho[9][12]= '-';
         caminho[9][13]= '-';
         caminho[9][14]= '-';
         caminho[10][2]= '-';
         caminho[11][2]= '-';
         caminho[11][7]= '-';
         caminho[11][12]= '$';
         caminho[12][2]= '-';
         caminho[12][7]= '-';
    }
     
     
     // print para matriz digitada 
     
     cout << "Labirinto \n";

     
     for(i=0;i<n;i++){
     	for(j=0;j<m;j++){
     	    cout << caminho[i][j];
     	}
     	cout << "\n";
     }


  //    chamada da função para o DFS (Profundidade)
    imprime=0;    // armazena quantidade de vertices
    tempo = clock(); 
   
   cout << "\nAlgoritmo DFS \n";     
   DFS(posi,posj);     
   cout << "\n";
   printf("Vertices visitados DFS= %d \n", imprime);
   printf("Tempo do Algorimo DFS:%f \n",(clock() - tempo) / (double)CLOCKS_PER_SEC);
   
    
    // zera novamente a matriz dos nos que ja foram visitados 
    for(i=0;i<n;i++){
     	for(j=0;j<m;j++){
           status[i][j]= false; // inicializa posicoes com falso, ou seja nao visitado
     	}
    }
    imprime=0; 
     
     
     // chamada da função para o BFS (Largura)
    tempo = clock();
     cout << "\n Algoritmo BFS \n";     
     BFS(posi,posj);     
     cout << "\n";
     printf("Vertices visitados BFS= %d \n", imprime);
     printf("Tempo do Algorimo BFS:%f \n",(clock() - tempo) / (double)CLOCKS_PER_SEC);
     
      // zera novamente a matriz dos nos que ja foram visitados 
    for(i=0;i<n;i++){
     	for(j=0;j<m;j++){
           status[i][j]= false; // inicializa posicoes com falso, ou seja nao visitado
     	}
    }
    imprime=0;
    tempo = clock();
     cout << "\nAlgoritmo Best \n";     
     Best(posi,posj);     
     cout << "\n";
     printf("Vertices visitados Best= %d \n", imprime);
     printf("Tempo do Algorimo Best:%f \n",(clock() - tempo) / (double)CLOCKS_PER_SEC);
     
    return 0;
}


// Esta funçao verifica se nao andaremos fora do limite da matriz ou em obstaculos
// retorna verdadeiro SSS satisfazer todas as restrições



bool valido ( int i, int j) { 

	int n,m;
    n=13;
    m=15; 
   
   

    if (  status[i][j]== true){
        return false;
        
   }
    
	// verifica posicao é  maior ou menor que linha
	if ( (i > n-1) || (i < 0 ) ){
		return false;
	}
	
	// verifica posicao é  maior ou menor que coluna
	if ( (j > m-1) || (j < 0 ) ){
		return false;
	}
	
	// verifica se posição tem obstaculo
	if ( caminho[i][j] == '-' ){
		return false;
	}
	return true;

}





 
// Busca em Profundidade - invertido
bool  DFS(int i, int j){     
	        
			status[i][j]= true;
			
			if (caminho[i][j]=='$'){
			   // cout << "achou \n";
			    cout << "(" << i << " " << j <<" )" <<" ";
			    imprime ++;
			    return true;
			}

			// ordem das posicoes
			// 1 2 3
			// 4 $ 6
			// 7 8 9		    
		    
		    // primeira pos 

		    if ( valido (i-1,j-1)  ){ // a função valido verifica se satisfaz as restrições
		        
		       if(  DFS(i-1,j-1)){ // se a função chamda obteve o retorno verdadeiro ou seja achou a 
		           cout << "(" << i << " " << j <<" )" <<" "; // solução e entao imprime a pos atual
		           return true; // retorna verdadeiro para o seu antecessor imprimir também
		       }
		    } 
		    
			// segunda pos
			if ( valido (i-1, j) ){
			    
		       if( DFS(i-1, j )){
		           
		           cout << "(" << i << " " << j <<" )" <<" ";
		           imprime ++;
		           return true; 
		       }     
		    }
		    
			// terceira pos 
	    	if ( valido (i-1,j+1) ){
		        
	            if(  DFS(i-1,j+1)){
	                
	               cout << "(" << i << " " << j <<" )" <<" ";
	               imprime ++;
		           return true; 
	            }
		    }
		    
			// quarta pos
			if ( valido (i,j-1) ){
			    
		       if( DFS(i,j-1  )){
		           cout << "(" << i << " " << j <<" )" <<" ";
		           imprime ++;
		           return true; 
		       }
		    }
		    
			// sexta pos
			if ( valido (i,j+1) ){
			    
		        if ( DFS(i, j+1 )){
		           cout << "(" << i << " " << j <<" )" <<" ";
		           imprime ++;
		           return true; 
		        }  
		    }
		    
			// setima pos
			if ( valido (i+1,j-1) ){
		    
		       if( DFS(i+1,j-1)){
		           cout << "(" << i << " " << j <<" )" <<" ";
		           imprime ++;
		           return true; 
		       }
			}
		    
	        // oitava pos 
	         if ( valido (i+1,j) ){
		    
		        if (DFS(i+1,j)){
		            
		           cout << "(" << i << " " << j <<" )" <<" ";
		           imprime ++;
		           return true; 
		        } 
			}
			
			// nona pos 
	     	if ( valido (i+1,j+1) ){
			    
		        if(DFS(i+1,j+1)){
		          cout << "(" << i << " " << j <<" )" <<" ";
		          imprime ++;
		           return true; 
		       }
	     	}
	       
	       // ele verifica se o retorno da função é verdadeiro se for verdadeiro retorno verdadeiro para a 
	       // função BFS e nao preciso executar o resto da chamada
		
	return false;
}

	

// Busca em Largura
void BFS(int i,int j){
    
    int atual;
    
    // pair para fazer uma fila com 2 elementos ao inves de 1
    
	pair<int,int> pii;
	
	 pii = make_pair(i,j);
	 //pii.first = i
	 //pii.first = j	

	queue< pair<int,int> > fila;	

	
	fila.push(pii); // fila da nossa BFS
	
	
	status[i][j] = true; 
	
	atual = 0; // atual posição que estamos na fila
	
	while(!fila.empty()){ // Enquanto a fila não for vazia
		
		
		
		while(true){
		pii = fila.front();
		fila.pop();

		    if(status[pii.first][pii.second] == false) break;
		    
		}
		status[pii.first][pii.second] = true; // coloca status de visitado
		imprime++;
		
		cout << "(" << pii.first << " " << pii.second <<" )" <<" "; // imprime posição
		
		if(caminho[pii.first][pii.second] =='$'){
		  //  cout << "parei em: " << pii.first << " " << pii.second; 
		     while (!fila.empty())
            {
                fila.pop();
            }
		    break; //lembrar da ordem de execução chupeta
		}
		
		 // para movermos o elemento da fila
		
			// ordem das posicoes
			// 1 2 3
			// 4 $ 6
			// 7 8 9		    
		    
		    // primeira pos
		     // pii.first-1, pii.second-1
		     
		    if ( valido (pii.first-1,pii.second-1)  ){ // verifica se a posição satisfaz as restrições
		         // pair
		         pii = make_pair(pii.first-1,pii.second-1); // concatena os novos indices
		         fila.push(pii);	// insere na fila
		    } 
		    
			// segunda pos
			if ( valido (pii.first-1, pii.second) ){
			    
			   pii = make_pair(pii.first-1, pii.second); 
		       fila.push(pii);
		    }
		    
			// terceira pos 
	    	if ( valido (pii.first-1,pii.second+1) ){
	    	    
		        pii = make_pair(pii.first-1,pii.second+1); 
	            fila.push(pii);
		    }
		    
			// quarta pos
			if ( valido (pii.first,pii.second-1) ){
			    
			   pii = make_pair(pii.first,pii.second-1  );  
		       fila.push(pii);
		    }
		    
			// sexta pos
			if ( valido (pii.first,pii.second+1) ){
			    pii = make_pair(pii.first, pii.second+1);
		        fila.push(pii);
		       
		    }
		    
			// setima pos
			if ( valido (pii.first+1,pii.second-1) ){
		       pii = make_pair(pii.first+1,pii.second-1); 
		       fila.push(pii);
			}
		    
	        // oitava pos 
	        if ( valido (pii.first+1,pii.second) ){
	 	        pii = make_pair(pii.first+1,pii.second); 
	 	        fila.push(pii);
			}
			
			// nona pos 
	     	if ( valido (pii.first+1,pii.second+1) ){
			    pii = make_pair(pii.first+1,pii.second+1);
		        fila.push(pii);
	       }
	 	
	}
}



	


void Best(int i,int j){
	// Para a função heurista sera utilizado distancia entre dois pontos
    
    int atual,auxi,auxj;
    float distanciaFinal,distanciaAtual;
    bool achou; 

	    
    // pair para fazer uma fila com 2 elementos ao inves de 1
    
	pair<int,int> pii;
	
	 pii = make_pair(i,j);
	 //pii.first = i
	 //pii.first = j	

	queue< pair<int,int> > fila;	
	fila.push(pii); // fila da nossa BFS
//	cout << pii.first << pii.second;
	//status[i][j] = true; 	
	atual = 0; // atual posição que estamos na fila
	
	while(!fila.empty()){ // Enquanto a fila não for vazia

	//	pii = fila.front();
	//	fila.pop();
		
		while(true){

		pii = fila.front();
		fila.pop();

		    if(status[pii.first][pii.second] == false) break;
		    if ( (pii.first== 0 ) && (pii.second== 0)){
		    	break;

		    }
		    
		} 
		status[pii.first][pii.second] = true; // coloca status de visitado
		
		cout << "(" << pii.first << " " << pii.second <<" )" <<" "; // imprime posição
		imprime++;
		
		if(caminho[pii.first][pii.second] =='$'){
		  //  cout << "parei em: " << pii.first << " " << pii.second; 
		     while (!fila.empty())
            {
                fila.pop();
            }
		    break; //lembrar da ordem de execução chupeta
		}
		
		 // para movermos o elemento da fila
		
			// ordem das posicoes
			// 1 2 3
			// 4 $ 6
			// 7 8 9		    
		    
		    // primeira pos
		     // pii.first-1, pii.second-1
		
		achou=false;
		distanciaFinal=-1;

//		while(achou != false){

			if ( valido (pii.first-1,pii.second-1)  ){ 
			//	cout << "1"<< sqrt( pow(fimi - pii.first-1,2) + pow(fimj - pii.second-1,2 ) );
				distanciaAtual= sqrt( pow(fimi - pii.first-1,2) + pow(fimj - pii.second-1,2 ) ) ;

				if(distanciaFinal == -1 || distanciaFinal < distanciaAtual){

						auxi=pii.first-1;
						auxj=pii.second-1;
						distanciaFinal= distanciaAtual;
					}					
		    } 
		    
			// segunda pos
			if ( valido (pii.first-1, pii.second) ){

			  //  cout << "2 "<< sqrt( pow(fimi - pii.first-1,2) + pow(fimj -pii.second ,2 ) );
				distanciaAtual= sqrt( pow(fimi - pii.first-1,2) + pow(fimj -pii.second ,2 ) );

			   if(distanciaFinal == -1 || distanciaFinal < distanciaAtual){
					auxi=pii.first-1;
					auxj=pii.second;
					distanciaFinal= distanciaAtual;					
				}
		    }
		    
			// terceira pos 
	    	if ( valido (pii.first-1,pii.second+1) ){
	    	   // cout << "3" <<sqrt( pow(fimi - pii.first-1,2) + pow(fimj -pii.second+1 , 2)  );
	    		distanciaAtual=sqrt( pow(fimi - pii.first-1,2) + pow(fimj -pii.second+1 , 2) );
		       if(distanciaFinal == -1 || distanciaFinal < distanciaAtual){
					auxi=pii.first-1;
					auxj=pii.second+1;
					distanciaFinal= distanciaAtual;
				}
		    }
		    
			// quarta pos
			if ( valido (pii.first,pii.second-1) ){

			    //cout << "4" <<sqrt( pow(fimi - pii.first,2) + pow(fimj -pii.second-1 , 2) ) << "\n";
			    distanciaAtual= sqrt( pow(fimi - pii.first,2) + pow(fimj -pii.second-1 , 2) );
			  	if(distanciaFinal == -1 || distanciaFinal < distanciaAtual){
					auxi=pii.first;
					auxj=pii.second-1;
				    distanciaFinal=distanciaAtual;
				}
		    }
		    
			// sexta pos
			if ( valido (pii.first,pii.second+1) ){
				//cout << "6" <<  sqrt( pow(fimi - pii.first,2) + pow(fimj -pii.second+1 , 2) ) ;
				distanciaAtual= sqrt( pow(fimi - pii.first,2) + pow(fimj -pii.second+1 , 2) );
			    if(distanciaFinal == -1 || distanciaFinal < distanciaAtual){
					auxi=pii.first;
					auxj=pii.second+1;
					distanciaFinal=distanciaAtual;
				}		       
		    }
		    
			// setima pos

			if ( valido (pii.first+1,pii.second-1) ){
				distanciaAtual=sqrt( pow(fimi - pii.first+1,2) + pow(fimj -pii.second-1 , 2) ) ;
				//cout << "7" << sqrt( pow(fimi - pii.first+1,2) + pow(fimj -pii.second-1 , 2)  );
		       if(distanciaFinal == -1 || distanciaFinal < distanciaAtual){
					auxi=pii.first+1;
					auxj=pii.second-1;
					distanciaFinal= distanciaAtual;
				}
			}
		    
	        // oitava pos 
	        if ( valido (pii.first+1,pii.second) ){

	        	//cout << "8" <<sqrt( pow(fimi - pii.first+1,2) + pow(fimj -pii.second , 2)  ) ;
	        	distanciaAtual= sqrt( pow(fimi - pii.first+1,2) + pow(fimj -pii.second , 2) ) ;
	 	        if(distanciaFinal == -1 || distanciaFinal < distanciaAtual){
					auxi=pii.first+1;
					auxj=pii.second;
					distanciaFinal=distanciaAtual;
				}
			}
			
			// nona pos 
	     	if ( valido (pii.first+1,pii.second+1) ){

	     		// cout << "9" << sqrt( pow(fimi - pii.first+1,2) + pow(fimj -pii.second+1 , 2)  ) << "\n" ;
	     		distanciaAtual= sqrt( pow(fimi - pii.first+1,2) + pow(fimj -pii.second+1 , 2) ) ;
			    if(distanciaFinal == -1 || distanciaFinal < distanciaAtual){
					auxi=pii.first+1;
					auxj=pii.second+1;
					distanciaFinal=distanciaAtual;
				}
	       }

	  //     achou=true;

//		}




		 // apos encontrado vizinho com menor valor colocamos ele na fila    
		pii = make_pair(auxi,auxj); // concatena os novos indices
		fila.push(pii);	// insere na fila
	 	
	}
}




