import java.lang.reflect.*;

public class MahasiswaDecoder {
    private Mahasiswa m;


  MahasiswaDecoder(Mahasiswa mahasiswa) {
    this.m = mahasiswa;
  }



  public void addMatkul(String name) throws Exception {
    try {
        Method a = m.getClass().getDeclaredMethod("addMatkul", String.class);
        a.setAccessible(true);
        a.invoke(m, name);
    } catch (Exception e) {
        throw e;
    }
  }



  public int getNIM() throws Exception {
    try {
        Field n = m.getClass().getDeclaredField("NIM");
        n.setAccessible(true);
        return (int) n.get(m);
    } catch (Exception e) {
        throw e;
    }
  }



  public double getIPK() throws Exception {
    try {
        Field i = m.getClass().getDeclaredField("IPK");
        i.setAccessible(true);
        return (double) i.get(m);
    } catch (Exception e) {
        throw e;
    }
  }
}