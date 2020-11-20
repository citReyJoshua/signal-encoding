import java.util.Scanner;

class Main{
    
    static String tl = "┌", tr = "┐", bl = "└", br = "┘", h = "─", v = "│";
    public static void main(String[] args){

        Scanner read = new Scanner(System.in);
        String input = read.nextLine();
        String[] bits = input.split(" ");

        System.out.println("Pseudoternary signal:\n" + printPseudo(bits));
        System.out.println("Manchester signal:\n" + printMan(bits));
        System.out.println("Differential Manchester signal:\n" + printDMan(bits));
    }

    static String printPseudo(String[] bits){
        boolean state = false;
        String output ="";

        for (int i = 0; i < bits.length; i++){
            if (bits[i].equals("0")){
                state = !state;
                if(state)
                    output = output.concat(h);
                else
                    output = output.concat(" ");
                
            }
            else
                output = output.concat(" ");

            if(i < bits.length - 1){
                
                if (output.substring(output.length() - 1).equals(h))
                    output = output.concat(tr);
                else{
                    if (state)
                        output = output.concat(" ");
                    else{
                        if (bits[i+1].equals("0"))
                            output = output.concat(tl);
                        else
                            output = output.concat(" ");
                    }
                }
            } 
        }
        output = output.concat("\n");
        state = false;
        for (int i = 0; i < bits.length; i++){
            if(bits[i].equals("0")){
                state = !state;
                output = output.concat(" ");
            }
            else
                output = output.concat(h);

            if( i < bits.length - 1){
                if (bits[i].equals("0")){
                    if(bits[i+1].equals("1")){
                        if (state){
                            output = output.concat(bl);
                        }
                        else{
                            output = output.concat(tl);
                        }
                    }
                    else
                        output = output.concat(v);
                }
                else{
                    if (bits[i+1].equals("0")){
                        if(state){
                            output = output.concat(tr);
                        }
                        else{
                            output = output.concat(br);
                        }
                    }
                    else{
                        output = output.concat(h);
                    }
                }
            }
        }
        output = output.concat("\n");
        state = false;
        for(int i = 0; i < bits.length; i++){
            if(bits[i].equals("0")){
                state = !state;
                if(state){
                    output = output.concat(" ");
                }
                else{
                    output = output.concat(h);
                }
            }
            else
                output = output.concat(" ");

            if (i < bits.length - 1){
                if (output.substring(output.length() - 1).equals(h)){
                    output = output.concat(br);
                }
                else{
                    if(state){
                        if (bits[i+1].equals("0")){
                            output = output.concat(bl);
                        }
                        else{
                            output = output.concat(" ");
                        }
                    }
                    else{
                        output = output.concat(" ");
                    }
                }
            }
        }
        output = output.concat("\n");
        return output;
    }

    static String printMan(String[] bits){
        String output = "";
        for(int i = 0; i < bits.length; i++){
            if(bits[i].equals("1"))
                output = output.concat(tl);
            else
                output = output.concat(tr);
            
            if (i < bits.length - 1){
                if (bits[i].equals("1")){
                    if (bits[i+1].equals("1"))
                        output = output.concat(tr);
                    else
                        output = output.concat(h);  
                }
                else{
                    if(bits[i+1].equals("1"))
                        output = output.concat(" ");
                    else
                        output = output.concat(tl);
                }
            }
        }
        output = output.concat("\n");
        for(int i = 0; i < bits.length; i++){
            if(bits[i].equals("1"))
                output = output.concat(br);
            else
                output = output.concat(bl);
            
            if (i < bits.length - 1){
                if (bits[i].equals("1")){
                    if (bits[i+1].equals("1"))
                        output = output.concat(bl);
                    else
                        output = output.concat(" ");  
                }
                else{
                    if(bits[i+1].equals("1"))
                        output = output.concat(h);
                    else
                        output = output.concat(br);
                }
            }
        }
        return output;
    }

    static String printDMan(String[] bits){
        String output = "";
        boolean state = true;
        String current = tr;
        for(int i = 0; i < bits.length; i++){

            if(bits[i].equals("1")){
                state = !state;
                if (state)
                    current = tr;
                else
                    current = tl;
            }
                output = output.concat(current);
            

            if(i < bits.length - 1){
                if(state){
                    if(bits[i+1].equals("1")){
                        output = output.concat(" ");
                    }
                    else{
                        output = output.concat(tl);
                    }
                }
                else{
                    if(bits[i+1].equals("1")){
                        output = output.concat(h);
                    }
                    else{
                        output = output.concat(tr);
                    }
                }
            }
        }
        output = output.concat("\n");
        state = true;
        current = bl;
        for(int i = 0; i < bits.length; i++){

            if(bits[i].equals("1")){
                state = !state;
                if (state)
                    current = bl;
                else
                    current = br;
            }
            
            output = output.concat(current);
            if(i < bits.length - 1){
                if(state){
                    if(bits[i+1].equals("1")){
                        output = output.concat(h);
                    }
                    else{
                        output = output.concat(br);
                    }
                }
                else{
                    if(bits[i+1].equals("1")){
                        output = output.concat(" ");
                    }
                    else{
                        output = output.concat(bl);
                    }
                }
            }
        }

        return output;
    }
}