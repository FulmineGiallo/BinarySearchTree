
// ...
#include <iostream>
using namespace std;
#include "test.hpp"
#include <string>
#include <string.h>
#include <string>
#include <typeinfo>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>    // std::shuffle
#include <iostream>
#include "../vector/vector.hpp"
#include "../bst/bst.hpp"
namespace lasd
{
 std::string chars {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
 std::random_device rd;
 std::mt19937 generator(rd());
 std::string rand_str (int length)
 {
    std::string output (chars);
    std::shuffle(output.begin(), output.end(), generator);
    return output.substr(0, length);
 }
 void riempiString(Vector<string>& v, int dim)
 {
   for(unsigned int i=0; i < dim; i++)
   {
      v[i] = rand_str(5);
   }
 }
 template<typename Data>
 void riempi(Vector<Data>& v, int dim)
 {
     Data dataRandom;
     srand ((unsigned int)time(NULL));
     std::string type_name();

     for(unsigned int i = 0; i < dim; i++)
     {
        dataRandom = (Data)rand() / 100 + 1;
        v[i] = dataRandom;
     }
 }


 void MenuSearch(int type, int dim)
 {
    int scelta = -1;
    int function = 1;
    lasd::Vector<int> vecint(dim);
    lasd::Vector<float> vecfloat(dim);
    lasd::Vector<string> vecstring(dim);

    typename BinaryTree<int>::Node* node_int;
    typename BinaryTree<float>::Node* node_float;
    typename BinaryTree<string>::Node* node_string;


    if(type == 1)
      riempi(vecint, dim);

    if(type == 2)
      riempi(vecfloat, dim);

    if(type == 3)
      riempiString(vecstring, dim);

    BST<int> treeint(vecint);
    BST<float> treefloat(vecfloat);
    BST<string> treestring(vecstring);

    BTPostOrderIterator<int> postorder_int(treeint);
    BTPostOrderIterator<float> postorder_float(treefloat);
    BTPostOrderIterator<string> postorder_string(treestring);

    BTInOrderIterator<int> inorder_int(treeint);
    BTInOrderIterator<float> inorder_float(treefloat);
    BTInOrderIterator<string> inorder_string(treestring);

    BTBreadthIterator<int> breadth_int(treeint);
    BTBreadthIterator<float> breadth_float(treefloat);
    BTBreadthIterator<string> breadth_string(treestring);

    BTPreOrderIterator<int> preorder_int(treeint);
    BTPreOrderIterator<float> preorder_float(treefloat);
    BTPreOrderIterator<string> preorder_string(treestring);

    node_int = &treeint.Root();
    node_float = &treefloat.Root();
    node_string = &treestring.Root();

    cout << "Benevenuto nel menu del BinaryTreeVec" << endl;
    while(scelta != 0)
    {

      cout << endl;
      cout << "Cosa vuoi testare?" << endl;

      cout << "1. Navigazione Albero con i Nodi" << endl;
      cout << "2. Navigazione Albero con gli Iteratori" << endl;
      cout << "3. Visualizzazioni elementi {Ampiezza, Pre-ordine, ordine, post-ordine}" << endl;
      cout << "4. Controllo di esistenza di un valore" << endl;
      cout << "5. Funzioni Fold" << endl;
      cout << "6. Minimo" << endl;
      cout << "7. Massimo" << endl;
      cout << "8. Predecessore" << endl;
      cout << "9. Successore" << endl;
      cout << "10. Inserisci" << endl;
      cout << "11. Rimuovi" << endl;
      cout << "12. Size Albero" << endl;
      cout << "0. Per uscire dal programma" << endl;
      cin >> scelta;
      cout << endl;
      if(scelta == 1)
      {
        int options = -1;
        int elementoModificato = 0;

        while(options != 0)
        {
          cout << "Opzioni:" << endl;
          cout << "1: Vai verso Figlio SX se esiste" << endl;
          cout << "2: Vai verso Figlio DX se esiste" << endl;
          cout << "3: Visualizza l'elemento di questo nodo."<< endl;
          cout << "4: Modifica l'elemento di questo nodo." << endl;
          cout << "0: Per tornare al Menu Precedente" << endl;
          cin >> options;
          if(type == 1)
          {
            if(options == 1)
            {
              if(!treeint.Empty())
                  if(node_int->HasLeftChild())
                    node_int = &node_int->LeftChild();
                  else
                    cout << "Non puoi andare a sinistra, non ha figlio sx questo nodo" << endl;
            }
            if(options == 2)
            {
              if(!treeint.Empty())
                  if(node_int->HasRightChild())
                    node_int = &node_int->RightChild();
                  else
                    cout << "Non puoi andare a destra, non ha figlio dx questo nodo" << endl;
            }
            if(options == 3)
              cout << "Elemento del nodo corrente: " << node_int->Element() << endl;
            if(options  == 4)
            {
              cout << "Inserisci un elemento che vuoi inserire nel nodo corrente" << endl;
              cin  >> elementoModificato;
              node_int->Element() = elementoModificato;
              cout << "Elemento inserito" << endl;
            }
          }
          if(type == 2)
          {
            if(options == 1)
            {
              if(!treeint.Empty())
                  if(node_float->HasLeftChild())
                    node_float = &node_float->LeftChild();
                  else
                    cout << "Non puoi andare a sinistra, non ha figlio sx questo nodo" << endl;
            }
            if(options == 2)
            {
              if(!treeint.Empty())
                  if(node_float->HasRightChild())
                    node_float = &node_float->RightChild();
                  else
                    cout << "Non puoi andare a destra, non ha figlio dx questo nodo" << endl;
            }
            if(options == 3)
              cout << "Elemento del nodo corrente: " << node_float->Element() << endl;
            if(options  == 4)
            {
              cout << "Inserisci un elemento che vuoi inserire nel nodo corrente" << endl;
              cin  >> elementoModificato;
              node_float->Element() = elementoModificato;
              cout << "Elemento inserito" << endl;
            }
          }
          if(type == 3)
          {
            if(options == 1)
            {
              if(!treeint.Empty())
                  if(node_string->HasLeftChild())
                    node_string = &node_string->LeftChild();
                  else
                    cout << "Non puoi andare a sinistra, non ha figlio sx questo nodo" << endl;
            }
            if(options == 2)
            {
              if(!treeint.Empty())
                  if(node_string->HasRightChild())
                    node_string = &node_string->RightChild();
                  else
                    cout << "Non puoi andare a destra, non ha figlio dx questo nodo" << endl;
            }
            if(options == 3)
              cout << "Elemento del nodo corrente: " << node_string->Element() << endl;
            if(options  == 4)
            {
              cout << "Inserisci un elemento che vuoi inserire nel nodo corrente" << endl;
              cin  >> elementoModificato;
              node_string->Element() = elementoModificato;
              cout << "Elemento inserito" << endl;
            }
          }
        }
      }
      if(scelta == 2)
      {
        int choose = -1;
        int chooseOperator = 0;
        int x = 0;
        float x1;
        string x2 = "";
        while (choose != 0)
        {
          cout << "1. Ampiezza" << endl;
          cout << "2. Pre-Ordine" << endl;
          cout << "3. Ordine" << endl;
          cout << "4. Post-Ordine" << endl;
          cout << "0. Per tornare indietro, gli iteratori rimaranno nel loro stato" << endl;
          cin  >> choose;
          if(choose == 1)
          {
            cout << "1: Visualizza l'elemento corrente (operator *)" << endl;
            cout << "2: Vai avanti con l'iterator (operator ++)" << endl;
            cout << "3: Modifica quell'elemento" << endl;
            cin  >> chooseOperator;
            if(type == 1 && chooseOperator == 1)
            {
              if(!breadth_int.Terminated())
                cout << "Elemento corrente: " << *breadth_int << endl;
            }
            if(type == 1 && chooseOperator == 2)
            {
              if(!breadth_int.Terminated())
              {
                ++breadth_int;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 1 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x;
              *breadth_int = x;
              cout << "Elemento cambiato con successo!" << endl;
            }
            if(type == 2 && chooseOperator == 1)
            {
              if(!breadth_float.Terminated())
                cout << "Elemento corrente: " << *breadth_float << endl;
            }
            if(type == 2 && chooseOperator == 2)
            {
              if(!breadth_float.Terminated())
              {
                ++breadth_float;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 2 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x1;
              *breadth_float = x1;
              cout << "Elemento cambiato con successo!" << endl;
            }
            if(type == 3 && chooseOperator == 1)
            {
              if(!breadth_string.Terminated())
                cout << "Elemento corrente: " << *breadth_string << endl;
            }
            if(type == 3 && chooseOperator == 2)
            {
              if(!breadth_string.Terminated())
              {
                ++breadth_string;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 3 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x2;
              *breadth_string = x2;
              cout << "Elemento cambiato con successo!" << endl;
            }
          }
          if(choose == 2)
          {
            cout << "1: Visualizza l'elemento corrente (operator *)" << endl;
            cout << "2: Vai avanti con l'iterator (operator ++)" << endl;
            cout << "3: Modifica quell'elemento" << endl;
            cin  >> chooseOperator;
            if(type == 1 && chooseOperator == 1)
            {
              if(!preorder_int.Terminated())
                cout << "Elemento corrente: " << *preorder_int << endl;
            }
            if(type == 1 && chooseOperator == 2)
            {
              if(!preorder_int.Terminated())
              {
                ++preorder_int;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 1 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x;
              *preorder_int = x;
              cout << "Elemento cambiato con successo!" << endl;
            }
            if(type == 2 && chooseOperator == 1)
            {
              if(!preorder_float.Terminated())
                cout << "Elemento corrente: " << *preorder_float << endl;
            }
            if(type == 2 && chooseOperator == 2)
            {
              if(!preorder_float.Terminated())
              {
                ++preorder_float;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 2 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x1;
              *preorder_float = x1;
              cout << "Elemento cambiato con successo!" << endl;
            }
            if(type == 3 && chooseOperator == 1)
            {
              if(!preorder_string.Terminated())
                cout << "Elemento corrente: " << *preorder_string << endl;
            }
            if(type == 3 && chooseOperator == 2)
            {
              if(!preorder_string.Terminated())
              {
                ++preorder_string;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 3 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x2;
              *preorder_string = x2;
              cout << "Elemento cambiato con successo!" << endl;
            }
            cout << "Ritorno al MENU Principale, ritorna qui per continuare con gli iteratori" << endl;
          }
          if(choose == 3)
          {
            cout << "1: Visualizza l'elemento corrente (operator *)" << endl;
            cout << "2: Vai avanti con l'iterator (operator ++)" << endl;
            cout << "3: Modifica quell'elemento" << endl;
            cin  >> chooseOperator;
            if(type == 1 && chooseOperator == 1)
            {
              if(!inorder_int.Terminated())
                cout << "Elemento corrente: " << *inorder_int << endl;
            }
            if(type == 1 && chooseOperator == 2)
            {
              if(!inorder_int.Terminated())
              {
                ++inorder_int;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 1 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x;
              *inorder_int = x;
              cout << "Elemento cambiato con successo!" << endl;
            }
            if(type == 2 && chooseOperator == 1)
            {
              if(!inorder_float.Terminated())
                cout << "Elemento corrente: " << *inorder_float << endl;
            }
            if(type == 2 && chooseOperator == 2)
            {
              if(!inorder_float.Terminated())
              {
                ++inorder_float;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 2 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x1;
              *inorder_float = x1;
              cout << "Elemento cambiato con successo!" << endl;
            }
            if(type == 3 && chooseOperator == 1)
            {
              if(!inorder_string.Terminated())
                cout << "Elemento corrente: " << *inorder_string << endl;
            }
            if(type == 3 && chooseOperator == 2)
            {
              if(!inorder_string.Terminated())
              {
                ++inorder_string;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 3 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x2;
              *inorder_string = x2;
              cout << "Elemento cambiato con successo!" << endl;
            }
          }
          if(choose == 4)
          {
            cout << "1: Visualizza l'elemento corrente (operator *)" << endl;
            cout << "2: Vai avanti con l'iterator (operator ++)" << endl;
            cout << "3: Modifica quell'elemento" << endl;
            cin  >> chooseOperator;
            if(type == 1 && chooseOperator == 1)
            {
              if(!postorder_int.Terminated())
                cout << "Elemento corrente: " << *postorder_int << endl;
            }
            if(type == 1 && chooseOperator == 2)
            {
              if(!postorder_int.Terminated())
              {
                ++postorder_int;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 1 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x;
              *postorder_int = x;
              cout << "Elemento cambiato con successo!" << endl;
            }
            if(type == 2 && chooseOperator == 1)
            {
              if(!postorder_float.Terminated())
                cout << "Elemento corrente: " << *postorder_float << endl;
            }
            if(type == 2 && chooseOperator == 2)
            {
              if(!postorder_float.Terminated())
              {
                ++postorder_float;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 2 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x1;
              *postorder_float = x1;
              cout << "Elemento cambiato con successo!" << endl;
            }
            if(type == 3 && chooseOperator == 1)
            {
              if(!postorder_string.Terminated())
                cout << "Elemento corrente: " << *postorder_string << endl;
            }
            if(type == 3 && chooseOperator == 2)
            {
              if(!postorder_string.Terminated())
              {
                ++postorder_string;
                cout << "Operator ++ applicato" << endl;
              }
            }
            if(type == 3 && chooseOperator == 3)
            {
              cout << "Inserisci l'elemento" << endl;
              cin  >> x2;
              *postorder_string = x2;
              cout << "Elemento cambiato con successo!" << endl;
            }
          }
        }

      }
      if(scelta == 3)
      {
        int choose = 0;
        cout << "1. Ampiezza" << endl;
        cout << "2. Pre-Ordine" << endl;
        cout << "3. Ordine" << endl;
        cout << "4. Post-Ordine" << endl;
        cin  >> choose;
        if(choose == 1)
        {
          if(type == 1)
          {
            cout << "Albero  In Ampiezza =  ";
            treeint.MapBreadth([](int & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 2)
          {
            cout << "Albero  In Ampiezza =  ";
            treefloat.MapBreadth([](float & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 3)
          {
              cout << "Albero In Ampiezza =  ";
            treestring.MapBreadth([](string & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
        }
        if(choose == 2)
        {
          if(type == 1)
          {
            cout << "Albero  In Pre-Ordine =  ";
            treeint.MapPreOrder([](int & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 2)
          {
              cout << "Albero  In Pre-Ordine =  ";
            treefloat.MapPreOrder([](float & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 3)
          {
              cout << "Albero  In Pre-Ordine =  ";
            treestring.MapPreOrder([](string & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
        }
        if(choose == 3)
        {
          if(type == 1)
          {
              cout << "Albero  InOrder =  ";
            treeint.MapInOrder([](int & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 2)
          {
            cout << "Albero  InOrder =  ";
            treefloat.MapInOrder([](float & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 3)
          {
            cout << "Albero  InOrder =  ";
            treestring.MapInOrder([](string & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
        }
        if(choose == 4)
        {
          if(type == 1)
          {
            cout << "Albero  In PostOrder =  ";
            treeint.MapPostOrder([](int & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 2)
          {
            cout << "Albero  In PostOrder =  ";
            treefloat.MapPostOrder([](float & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
          if(type == 3)
          {
            cout << "Albero  In PostOrder =  ";
            treestring.MapPostOrder([](string & dat, void * ) {
              cout << dat << "  ";
            }, nullptr);
            cout << endl;
          }
        }

      }
      if(scelta == 4)
      {
        cout << "Che Elemento vuoi cercare nell'albero?" << endl;
        if(type == 1)
        {
          int search = 0;
          cin >> search;
          if(treeint.Exists(search))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
        }
        if(type == 2)
        {
          float search = 0;
          cin >> search;
          if(treefloat.Exists(search))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
        }
        if(type == 3)
        {
          string search;
          cin >> search;
          if(treestring.Exists(search))
            cout << "Elemento trovato" << endl;
          else
            cout << "Elemento non trovato" << endl;
        }
      }
      if(scelta == 5 && type == 1) // INT
      {
          cout << "1. Prodotto per gli interi minori di n (Funzione Fold)" << endl;
          int n2 = 0;
          int prod = 1;
          cout << "Inserisci un intero" << endl;
          cin  >> n2;
          treeint.FoldPreOrder([](const int & dat,
              const void * n2, void * prod) {
              if (dat < * ((int * ) n2)) {
                *((int * ) prod) *= dat;
              }
            }, & n2, & prod);
          cout << "Il prodotto degli interi (minori di " << n2 << ") e' : " << prod << endl;
      }
      if(scelta == 5 && type == 2) //Float
      {
        cout << "1. Somma per i float maggiori di n (Funzione Fold)" << endl;
          float n2 = 0;
          float sum = 0;
            cout << "Inserisci un n(float):" << endl;
            cin  >> n2;
            treefloat.FoldPreOrder([](const float & dat,
                const void * n2, void * sum) {
                if (dat > * ((float * ) n2)) {
                  *((float * ) sum) += dat;
                }
              }, & n2, & sum);
              cout << "La somma dei float (maggiori di " << n2 << ") e' : " << sum << endl;
      }
      if(scelta == 5 && type == 3) //String
      {
        cout << "1. Concatenazione per le stringhe con lunghezza minore o uguale a n (Funzione Fold)" << endl;
          string stringa = "";
          int n2 = 0;
          cout << "Inserisci la lunghezza" << endl;
          cin >> n2;
          treestring.FoldPreOrder([](const string & dat,
             const void * n2, void * stringa) {
             if (dat.size() <= * ((int * ) n2)) {
               *((string * ) stringa) += dat;
             }
           }, & n2, & stringa);

           cout << "Concatenazione delle stringhe (con lunghezza minore o uguale a " << n2 << ") e' : " << stringa << endl;
        
      }
      if(scelta == 6)
      {
        int scelta;
        cout << "1. Leggi Minimo" << endl;
        cout << "2. Rimuovi Minimo" << endl;
        cout << "3. Leggi Minimo  e Rimuovilo" << endl;
        cin  >> scelta;
        if(type == 1 && scelta == 1)
        {
          cout << "Minimo : " << treeint.Min() << endl;
        }
        if(type == 2 && scelta == 1)
        {
          cout << "Minimo : " << treefloat.Min() << endl;
        }
        if(type == 3 && scelta == 1)
        {
          cout << "Minimo : " << treestring.Min() << endl;
        }
        if(type == 1 && scelta == 2)
        {
          cout << "Rimosso Minimo : " << endl;
          treeint.RemoveMin();
        }
        if(type == 2 && scelta == 2)
        {
          cout << "Rimosso Minimo : " << endl;
          treefloat.RemoveMin();
        }
        if(type == 3 && scelta == 2)
        {
          cout << "Rimosso Minimo : " << endl;
          treestring.RemoveMin();
        }
        if(type == 1 && scelta == 3)
        {
            cout << "Rimosso Minimo " << treeint.MinNRemove() << endl;
        }
        if(type == 2 && scelta == 3)
        {
            cout << "Rimosso Minimo " << treefloat.MinNRemove() << endl;
        }
        if(type == 3 && scelta == 3)
        {
            cout << "Rimosso Minimo " << treestring.MinNRemove() << endl;
        }
      }
      if(scelta == 7)
      {
        int scelta;
        cout << "1. Leggi Massimo" << endl;
        cout << "2. Rimuovi Massimo" << endl;
        cout << "3. Leggi Massimo  e Rimuovilo" << endl;
        cin  >> scelta;
        if(type == 1 && scelta == 1)
        {
          cout << "Massimo : " << treeint.Max() << endl;
        }
        if(type == 2 && scelta == 1)
        {
          cout << "Massimo : " << treefloat.Max() << endl;
        }
        if(type == 3 && scelta == 1)
        {
          cout << "Massimo : " << treestring.Max() << endl;
        }
        if(type == 1 && scelta == 2)
        {
          cout << "Rimosso Massimo : " << endl;
          treeint.RemoveMax();
        }
        if(type == 2 && scelta == 2)
        {
          cout << "Rimosso Massimo : " << endl;
          treefloat.RemoveMax();
        }
        if(type == 3 && scelta == 2)
        {
          cout << "Rimosso Massimo : " << endl;
          treestring.RemoveMax();
        }
        if(type == 1 && scelta == 3)
        {
            cout << "Rimosso Massimo " << treeint.MaxNRemove() << endl;
        }
        if(type == 2 && scelta == 3)
        {
            cout << "Rimosso Massimo " << treefloat.MaxNRemove() << endl;
        }
        if(type == 3 && scelta == 3)
        {
            cout << "Rimosso Massimo " << treestring.MaxNRemove() << endl;
        }
      }
      if(scelta == 8)
      {
        int scelta = 0;
        cout << "1. Predecessore" << endl;
        cout << "2. Remove Predecessore" << endl;
        cout << "3. Leggi Predecessore e Rimuovilo" << endl;
        cin  >> scelta;
        if(type == 1 && scelta == 1)
        {
          int pre = 0;
          cout << "Inserisci il Predecessore da trovare" << endl;
          cin  >> pre;
          cout << "Predecessore di " << pre << " : " << treeint.Predecessor(pre) << endl;
        }
        if(type == 2 && scelta == 1)
        {
          float pre = 0;
          cout << "Inserisci il Predecessore da trovare" << endl;
          cin  >> pre;
          cout << "Predecessore di " << pre << " : " << treefloat.Predecessor(pre) << endl;
        }
        if(type == 3 && scelta == 1)
        {
          string pre = "";
          cout << "Inserisci il Predecessore da trovare" << endl;
          cin  >> pre;
          cout << "Predecessore di " << pre << " : " << treestring.Predecessor(pre) << endl;
        }
        if(type == 1 && scelta == 2)
        {
          int val = 0;
          cout << "Inserisci elemento" << endl;
          cout << "Rimosso Predecessore se esiste : " << endl;
          treeint.RemovePredecessor(val);
        }
        if(type == 2 && scelta == 2)
        {
          float val = 0;
          cout << "Inserisci elemento" << endl;
          cin  >> val;
          cout << "Rimosso Predecessore se esiste : " << endl;
          treefloat.RemovePredecessor(val);
        }
        if(type == 3 && scelta == 2)
        {
          string val = "";
          cout << "Inserisci elemento" << endl;
          cin  >> val;
          cout << "Rimosso Predecessore se esiste : " << endl;
          treestring.RemovePredecessor(val);
        }
        if(type == 1 && scelta == 3)
        {
          int val = 0;
          cout << "Inserisci elemento" << endl;
          cin  >> val;
          cout << "Rimosso Predecessore se esiste : " << treeint.PredecessorNRemove(val) << endl;

        }
        if(type == 2 && scelta == 3)
        {
          float val = 0;
          cout << "Inserisci elemento" << endl;
          cin  >> val;
          cout << "Rimosso Predecessore se esiste : " << treefloat.PredecessorNRemove(val) << endl;

        }
        if(type == 3 && scelta == 3)
        {
          string val = "";
          cout << "Inserisci elemento" << endl;
          cin  >> val;
          cout << "Rimosso Predecessore se esiste : " << treestring.PredecessorNRemove(val) << endl;
        }
      }
      if(scelta == 9)
      {
        int scelta = 0;
        cout << "1. Successore" << endl;
        cout << "2. Remove Successore" << endl;
        cout << "3. Leggi Successore e Rimuovilo" << endl;
        cin  >> scelta;
        if(type == 1 && scelta == 1)
        {
          int pre = 0;
          cout << "Inserisci il Successore da trovare" << endl;
          cin  >> pre;
          cout << "Successore di " << pre << " : " << treeint.Successor(pre) << endl;
        }
        if(type == 2 && scelta == 1)
        {
          float pre = 0;
          cout << "Inserisci il Successore da trovare" << endl;
          cin  >> pre;
          cout << "Successore di " << pre << " : " << treefloat.Successor(pre) << endl;
        }
        if(type == 3 && scelta == 1)
        {
          string pre = "";
          cout << "Inserisci il Successore da trovare" << endl;
          cin  >> pre;
          cout << "Successore di " << pre << " : " << treestring.Successor(pre) << endl;
        }
        if(type == 1 && scelta == 2)
        {
          int val = 0;
          cout << "Inserisci elemento" << endl;
          cout << "Rimosso Successore se esiste : " << endl;
          treeint.RemoveSuccessor(val);
        }
        if(type == 2 && scelta == 2)
        {
          float val = 0;
          cout << "Inserisci elemento" << endl;
          cin  >> val;
          cout << "Rimosso Successore se esiste : " << endl;
          treefloat.RemoveSuccessor(val);
        }
        if(type == 3 && scelta == 2)
        {
          string val = "";
          cout << "Inserisci elemento" << endl;
          cin  >> val;
          cout << "Rimosso Successore se esiste : " << endl;
          treestring.RemoveSuccessor(val);
        }
        if(type == 1 && scelta == 3)
        {
          int val = 0;
          cout << "Inserisci elemento" << endl;
          cin  >> val;
          cout << "Rimosso Successore se esiste : " << treeint.SuccessorNRemove(val) << endl;

        }
        if(type == 2 && scelta == 3)
        {
          float val = 0;
          cout << "Inserisci elemento" << endl;
          cin  >> val;
          cout << "Rimosso PredeSuccessorecessore se esiste : " << treefloat.SuccessorNRemove(val) << endl;

        }
        if(type == 3 && scelta == 3)
        {
          string val = "";
          cout << "Inserisci elemento" << endl;
          cin  >> val;
          cout << "Rimosso Predecessore se esiste : " << treestring.SuccessorNRemove(val) << endl;
        }
      }
      if(scelta == 10)
      {
        cout << "Quando effettui un inserimento, assicurati che non è già presente, oppure l'elemento non verrà inserito " << endl;
        cout << "Cosa vuoi inserire?" << endl;
        if(type == 1)
        {
          int dato = 0;
          cin >> dato;
          treeint.Insert(dato);
        }
        if(type == 2)
        {
          float dato = 0;
          cin >> dato;
          treefloat.Insert(dato);
        }
        if(type == 3)
        {
          string dato = "";
          cin >> dato;
          treestring.Insert(dato);
        }
      }
      if(scelta == 11)
      {
        cout << "Quando effettui una rimozione, assicurati che è presente, oppure l'elemento non verrà eliminato " << endl;
        cout << "Cosa vuoi eliminare?" << endl;
        if(type == 1)
        {
          int dato = 0;
          cin >> dato;
          treeint.Remove(dato);
        }
        if(type == 2)
        {
          float dato = 0;
          cin >> dato;
          treefloat.Remove(dato);
        }
        if(type == 3)
        {
          string dato = "";
          cin >> dato;
          treestring.Remove(dato);
        }
      }
      if(scelta == 12)
      {
        if(type == 1)
         cout << "Size : " << treeint.Size();
        if(type == 2)
         cout << "Size : " << treefloat.Size();
        if(type == 3)
         cout << "Size : " << treestring.Size();
      }

    }

 }
 void MenuUtente()
 {
   int chooseType = 0;
   int n = 0;
   cout << "___ MENU Esercizio 4 _____" << endl;
   cout << endl;
   cout << "Che tipo di dati vuoi utilizzare in questo albero?" << endl;
   cout << "1: int" << endl;
   cout << "2: float" << endl;
   cout << "3: String" << endl;
   cin  >> chooseType;
   cout << "Quanti elementi vuoi inserire all'interno dell'albero?" << endl;
   cin  >> n;

   MenuSearch(chooseType, n);
 }
}
