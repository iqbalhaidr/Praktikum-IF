import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.lang.Class;
import java.lang.reflect.*;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods(){
        ArrayList<String> res = new ArrayList<>();

        try {
            Class<?> g = Class.forName("Ghost");
            Method[] methodList = g.getDeclaredMethods();

            for (Method m : methodList) {
                res.add(m.getName());
            }
        } catch (ClassNotFoundException e) {}

        return new ArrayList<>(res);
    }   

    public Integer sumGhost() throws Exception{
        Integer ctr = 0;

        Class<?> g = Class.forName("Ghost");
        Object gObj = g.getDeclaredConstructor().newInstance();
        Method methodList[] = g.getDeclaredMethods();

        for (Method m : methodList) {
            if (m.getReturnType().equals(Integer.class)) {
                m.setAccessible(true);
                ctr += (Integer) m.invoke(gObj);
            }
        }

        return ctr;
    }

    public String letterGhost() throws Exception{
        String res = "";

        Class<?> g = Class.forName("Ghost");
        Object gObj = g.getDeclaredConstructor().newInstance();
        Method methodList[] = g.getDeclaredMethods();

        for (Method m : methodList) {
            if (m.getReturnType().equals(String.class)) {
                m.setAccessible(true);
                res += (String) m.invoke(gObj);
            }
        }

        return res;
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception{
        for (Secret s : sl) {
            if (s.isThis(email)) {
                Field f = s.getClass().getDeclaredField("uniqueId");
                f.setAccessible(true);
                return (String) f.get(s);
            }
        }
        return "NaN";
    }
}