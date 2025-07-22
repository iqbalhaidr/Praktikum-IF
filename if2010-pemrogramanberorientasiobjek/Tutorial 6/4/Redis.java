public class Redis<K, V> {
    private K key;
    private V value;
    private long ttl;

    public Redis(K key, V value, long ttl) {
        if (ttl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.key = key;
        this.value = value;
        this.ttl = ttl;
    }

    public K getKey() {
        return key;
    }

    public V getVal(long elapsedSeconds) {
        if (elapsedSeconds >= ttl) {
            throw new TtlExpiredException(key + " expired");
        }
        return value;
    }

    public void setKey(K key) {
        this.key = key;
    }

    public void setVal(V value) {
        this.value = value;
    }

    public long getRemainingTtl(long elapsedSeconds) {
        if (elapsedSeconds >= ttl) {
            return 0;
        } else {
            return ttl - elapsedSeconds;
        }
    }
    
    public void refresh(long newTtl) {
        if (newTtl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.ttl = newTtl;
    }

    public boolean isEqual(Redis<?, ?> other) {
        return key.equals(other.key) && value.equals(other.value);
    }

    public int nearEQ(Redis<?, ?> other) {
        boolean keyEq = key.equals(other.key);
        boolean valEq = value.equals(other.value);

        if (keyEq && valEq) {
            return 3;
        }
        if (valEq) {
            return 2;
        }
        if (keyEq) {
            return 1;
        }
        return 0;
    }
}
