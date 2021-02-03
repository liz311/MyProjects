/* Created By Lizzy Asis */

public abstract class User {
    private int id;
    private String firstName;
    private String lastName;
    private String email;

    public User(int id, String firstName, String lastName, String email){
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.email = email;
    }

    public int getId(){
        return id;
    }

    public void setId(int id){
        if(id > 0 )
            this.id = id;
        else{
            System.out.println("error");
        }
    }

    public String getFirstName(){
        return firstName;
    }

    public void setFirstName(String firstName){
        this.firstName = firstName;
    }

}
