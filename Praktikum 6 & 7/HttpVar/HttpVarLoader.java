import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;

public class HttpVarLoader {

    private HashMap<String, String> headers;
    private HashMap<String, String> body;
    private HashMap<String, String> query;
    private HashMap<String, String> cookie;

    public HttpVarLoader(HashMap<String, String> headers, HashMap<String, String> body, HashMap<String, String> query,
            HashMap<String, String> cookie) {
        this.headers = new HashMap<>(headers);
        this.body = new HashMap<>(body);
        this.query = new HashMap<>(query);
        this.cookie = new HashMap<>(cookie);
    }

    public void load(Object obj) throws NullPointerException, InvocationTargetException {
        if (obj == null) {
            throw new NullPointerException();
        }

        Class<?> clazz = obj.getClass();

        // Process fields
        for (Field field : clazz.getDeclaredFields()) {
            if (field.isAnnotationPresent(HttpVar.class)) {
                HttpVar httpVar = field.getAnnotation(HttpVar.class);
                String value = getValue(httpVar.type(), httpVar.name());
                if (value == null) {
                    throw new NullPointerException();
                }
                field.setAccessible(true);
                try {
                    field.set(obj, value);
                } catch (IllegalAccessException e) {
                    e.printStackTrace();
                }
            }
        }

        // Process methods
        for (Method method : clazz.getDeclaredMethods()) {
            if (method.isAnnotationPresent(HttpVar.class)) {
                HttpVar httpVar = method.getAnnotation(HttpVar.class);
                String value = getValue(httpVar.type(), httpVar.name());
                if (value == null) {
                    throw new NullPointerException();
                }
                if (method.getParameterCount() == 1 && method.getParameterTypes()[0] == String.class) {
                    method.setAccessible(true);
                    try {
                        method.invoke(obj, value);
                    } catch (IllegalAccessException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    private String getValue(HttpVar.Type type, String name) {
        switch (type) {
            case Query:
                return query.get(name);
            case Header:
                return headers.get(name);
            case Cookie:
                return cookie.get(name);
            case Body:
                return body.get(name);
            default:
                return null;
        }
    }
}
