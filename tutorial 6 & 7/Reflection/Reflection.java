import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

public class Reflection {
    // TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT
    // TYPENYA
    // BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    // DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods() throws Exception {

        Class<?> ghost = Class.forName("Ghost");
        Method[] methods = ghost.getDeclaredMethods();
        ArrayList<String> result = new ArrayList<>();
        for (Method method : methods) {
            result.add(method.getName());
        }
        return result;
    }

    public Integer sumGhost() throws Exception {

        Class<?> ghostClass = Class.forName("Ghost");
        Method[] ghostMethods = ghostClass.getDeclaredMethods();
        Integer sum = 0;
        for (Method method : ghostMethods) {
            method.setAccessible(true);
            if (method.getReturnType().equals(Integer.class)) {
                // Call the method and cast the result to Integer
                Integer result = (Integer) method.invoke(ghostClass.newInstance());
                // Add the result to the sum
                sum += result;
            }
        }
        return sum;

    }

    public String letterGhost() throws Exception {
        Class<?> ghostClass = Class.forName("Ghost");
        Method[] ghostMethods = ghostClass.getDeclaredMethods();
        String concat = "";
        for (Method method : ghostMethods) {
            method.setAccessible(true);
            if (method.getReturnType().equals(String.class)) {
                // call the method and cast the result to String
                String result = (String) method.invoke(ghostClass.newInstance());
                // concat the result to the concat variable
                concat += result;
            }
        }
        return concat;
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception {
        for (Secret secret : sl) {
            if (secret.isThis(email)) {
                // set uniqueId accessible
                Field uniqueId = secret.getClass().getDeclaredField("uniqueId");
                uniqueId.setAccessible(true);
                return (String) uniqueId.get(secret);
            }
        }
        return "NaN";
    }
}