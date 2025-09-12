public class phuongtrinhbac2 
{
    public static void main(String[] args) 
    {
        float a = 1.0f;
        float b = -3.0f;
        float c = 2.0f;
        if(a == 0)
        {
            if(b == 0)
            {
                if(c == 0)
                {
                    System.out.println("Phương trình vô số nghiệm");
                }
                else
                {
                    System.out.println("Phương trình vô nghiệm");
                }
            }
            else
            {
                float x = -c/b;
                System.out.printf("Phương trình có nghiệm x = %f",x);
            }
        }
        else
        {
            float delta = b*b - 4*a*c;
            if(delta < 0)
            {
                System.out.println("Phương trình vô nghiệm");
            }
            else if(delta == 0)
            {
                float x = -b/(2*a);
                System.out.printf("Phương trình có nghiệm kép x1 = x2 = %f",x);
            }
            else
            {
                float x1 = (float)(-b + Math.sqrt(delta))/(2*a);
                float x2 = (float)(-b - Math.sqrt(delta))/(2*a);
                System.out.printf("Phương trình có hai nghiệm phân biệt x1 = %f và x2 = %f",x1,x2);
            }
        }
    }    
}
