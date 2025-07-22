class Couple<K, V> {
    private K key;
    private V val;

    public Couple(K key, V val) {
        this.key = key;
        this.val = val;
    }

    public K getKey() {
        return key;
    }

    public V getVal() {
        return val;
    }

    public void setKey(K key) {
        this.key = key;
    }

    public void setVal(V val) {
        this.val = val;
    }

    public boolean isEqual(Couple c) {
        return this.key == c.key && this.val == c.val;
    }

    public int nearEQ(Couple c) {
        if (this.val == c.val && this.key == c.key) {
            return 3;
        } else if (this.val == c.val && this.key != c.key) {
            return 2;
        } else if (this.key == c.key && this.val != c.val) {
            return 1;
        } else {
            return 0;
        }
    }

};