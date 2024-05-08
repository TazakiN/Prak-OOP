public class Result<T, E extends Exception> implements IResult<T, E> {
    private T data;
    private E error;

    // return new Result object with data based on input
    public static <T, E extends Exception> Result<T, E> ok(T data) {
        Result<T, E> result = new Result<>();
        result.data = data;
        return result;
    }

    // return new Result object with error based on input
    public static <T, E extends Exception> Result<T, E> err(E error) {
        Result<T, E> result = new Result<>();
        result.error = error;
        return result;
    }

    @Override
    public boolean isOk() {
        if (data != null) {
            return true;
        }
        return false;
    }

    @Override
    public boolean isErr() {
        if (error != null) {
            return true;
        }
        return false;
    }

    @Override
    public T unwrap() throws Exception {
        if (isOk()) {
            return data;
        } else {
            throw error;
        }
    }

    @Override
    public T unwrapOrElse(T defaultValue) {
        if (isOk()) {
            return data;
        } else {
            return defaultValue;
        }
    }

    @Override
    public T unwrapOrThrow(Exception defaultException) throws Exception {
        if (isOk()) {
            return data;
        } else {
            throw defaultException;
        }
    }

    // implement all other functions in the interface
}