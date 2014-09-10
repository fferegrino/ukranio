import java.util.Random;
import java.util.Scanner;

public class Ejercicio3 {
    private static final Random random = new Random();
    private int n;
    private String cadenota;
    
    public void setN(int n) {
        this.n = n;
    }
    
    public int cuenta(String cadenita ){
        int cnt = 0;
        for(int i = 0; i < n * 4; i+=4){
			for(int j  = 0; j < cadenita.length() && cadenota.charAt(i+j) == cadenita.charAt(j) ; j++){
					if(j ==cadenita.length()-1) cnt++;
			}
		}
		/*
        int ix = cadenota.indexOf(cadenita);
        while(ix >= 0)
        {
            cnt++;
            System.out.println(ix);
            ix = cadenota.indexOf(cadenita, ix+1);
        }
        */
        return cnt;
    }
    
    public String genera(){
        cadenota = "";
        for(int i = 0; i < n; i++){
            cadenota += randomChar();
            cadenota += randomChar();
            cadenota += randomChar();
            cadenota += " ";
        }
        return cadenota;
    }
    
    private char randomChar(){
        return (char) ('A' +(char) Math.abs((random.nextInt() % 26)));
    }
    
    public static void main(String[] args) {
        Ejercicio3 ej3 = new Ejercicio3();
        Scanner sc = new Scanner(System.in);
        if(args.length > 0){
            ej3.setN(Integer.parseInt(args[0]));
        }else{
            ej3.setN(sc.nextInt());
        }
        ej3.genera();
        System.out.println("Ocurrencias de IPN: " + ej3.cuenta("IPN"));
    }
    
}
