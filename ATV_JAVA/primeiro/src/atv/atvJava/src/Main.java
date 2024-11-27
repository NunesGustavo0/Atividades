public class Main {
    public static void main(String[] args) {
        Proprietario proprietario = new Proprietario("João Silva", "123.456.789-00", "99999-9999", "Rua Exemplo, 123");

        Veiculo veiculo1 = new Veiculo("ABC-1234", "Toyota", "2020", "Preto");
        Veiculo veiculo2 = new Veiculo("XYZ-5678", "Honda", "2018", "Branco");

        proprietario.adicionarVeiculo(veiculo1);
        proprietario.adicionarVeiculo(veiculo2);

        System.out.println("Lista de Veículos:");
        proprietario.listarVeiculos();

        System.out.println("\nAlterando a cor do primeiro veículo:");
        veiculo1.alterarCor("Vermelho");
        veiculo1.exibirInformacoes();

        System.out.println("\nRemovendo o segundo veículo:");
        proprietario.removerVeiculo("XYZ-5678");
        proprietario.listarVeiculos();
    }
}
