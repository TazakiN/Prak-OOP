import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class Streamer<T> implements IStreamer<T> {

    private List<T> data;

    public Streamer(List<T> data) {
        this.data = data;
    }

    public void forEach(Function<T, Void> consumer) {
        for (T item : data) {
            consumer.apply(item);
        }
    }

    public <R> IStreamer<R> map(Function<T, R> mapper) {
        List<R> mappedData = new ArrayList<>();
        for (T item : data) {
            mappedData.add(mapper.apply(item));
        }
        return new Streamer<>(mappedData);
    }

    public IStreamer<T> filter(Function<T, Boolean> predicate) {
        List<T> filteredData = new ArrayList<>();
        for (T item : data) {
            if (predicate.apply(item)) {
                filteredData.add(item);
            }
        }
        return new Streamer<>(filteredData);
    }

    public <R> R reduce(R initialValue, Function<R, Function<T, R>> reducer) {
        R acc = initialValue;
        for (T item : data) {
            acc = reducer.apply(acc).apply(item);
        }
        return acc;
    }

    public <R> IStreamer<R> flatMap(Function<T, IStreamer<R>> mapper) {
        List<R> flatMappedData = new ArrayList<>();
        for (T item : data) {
            IStreamer<R> mappedStream = mapper.apply(item);
            for (R mappedItem : mappedStream.collect()) {
                flatMappedData.add(mappedItem);
            }
        }
        return new Streamer<>(flatMappedData);
    }

    public T findFirst(Function<T, Boolean> predicate) {
        for (T item : data) {
            if (predicate.apply(item)) {
                return item;
            }
        }
        return null;
    }

    public T findLast(Function<T, Boolean> predicate) {
        for (int i = data.size() - 1; i >= 0; i--) {
            if (predicate.apply(data.get(i))) {
                return data.get(i);
            }
        }
        return null;
    }

    public T head() {
        if (data.size() > 0) {
            return data.get(0);
        }
        return null;
    }

    public IStreamer<T> tail() {
        if (data.size() > 0) {
            List<T> tailData = new ArrayList<>(data);
            tailData.remove(0);
            return new Streamer<>(tailData);
        }
        return new Streamer<>(new ArrayList<>());
    }

    public T last() {
        if (data.size() > 0) {
            return data.get(data.size() - 1);
        }
        return null;
    }

    public IStreamer<T> init() {
        if (data.size() > 0) {
            List<T> initData = new ArrayList<>(data);
            initData.remove(data.size() - 1);
            return new Streamer<>(initData);
        }
        return new Streamer<>(new ArrayList<>());
    }

    public IStreamer<T> takeFirst(int n) {
        if (n > data.size()) {
            return new Streamer<>(data);
        } else {
            return new Streamer<>(data.subList(0, n));
        }
    }

    public IStreamer<T> takeLast(int n) {
        if (n > data.size()) {
            return new Streamer<>(data);
        } else {
            return new Streamer<>(data.subList(data.size() - n, data.size()));
        }
    }

    public Boolean isEmpty() {
        return data.size() == 0;
    }

    public Integer count() {
        return data.size();
    }

    public Boolean some(Function<T, Boolean> predicate) {
        for (T item : data) {
            if (predicate.apply(item)) {
                return true;
            }
        }
        return false;
    }

    public Boolean every(Function<T, Boolean> predicate) {
        for (T item : data) {
            if (!predicate.apply(item)) {
                return false;
            }
        }
        return true;
    }

    public List<T> collect() {
        return data;
    }

    public void reverse() {
        List<T> reversedData = new ArrayList<>();
        for (int i = data.size() - 1; i >= 0; i--) {
            reversedData.add(data.get(i));
        }
        data = reversedData;
    }
}