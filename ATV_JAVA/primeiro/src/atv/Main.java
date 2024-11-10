package atv;

public class Main {
    public static void main(String[] args) {
        int cont;

        Caneta c1 =  new Caneta();
        c1.cor = "Azul";
        c1.modelo =  "Ponta fina";
        c1.ponta = 0.5F;
        c1.carga =  60;
        c1.tampada = false;

        Caneta c2 = new Caneta();
        c2.cor = "Verde";
        c2.tampada = true;
        c2.carga = 24;

        c1.status();
        System.out.print("\nVocê deseja tampar a caneta? ");
        c1.tampar();
        c1.status();
        System.out.print("Você deseja destampar a caneta? ");
        c1.destampar();
        c1.status();
        System.out.print("Você deseja desenhar um pouco?");
        cont=0;
        if(c1.tampada == false) {
            while (cont < 2) {
                c1.rabiscar();
                c1.status();
                cont += 1;
            }
        }else{
            System.out.print("Não é possivel rabiscar com a caneta tampada");
        }
        cont=0;
        if(c2.tampada == true) {
            while (cont < 2) {
                c2.rabiscar();
                System.out.println("\nCor: " + c2.cor);
                System.out.println("Capacidade: " + c2.carga);
                System.out.println("Tampada: " + c2.tampada);
                cont += 1;
            }
        }else{
            System.out.print("Não é possivel rabiscar com a caneta tampada");
        }
    }
}