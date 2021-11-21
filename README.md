# job-poster
Fundamentals of Software Engineering 1st project

Multiple user system for posting and searching job listings, The Users will be able to search for job listings in the system with different queries, and the Managers will be able to post these jobs. as well as seeing the candidates who applied for the job.

The system works with a file-based database and the interface is shown in the command line

## Database Structure
<table>
    <tr>
        <th colspan="2">User</th>
        <th colspan="2">Manager</th>
        <th colspan="2">Post</th>
        <th colspan="2">Applied</th>
    </tr>
    <tr>
        <th>Name</th>
        <th>Type</th>
        <th>Name</th>
        <th>Type</th>
        <th>Name</th>
        <th>Type</th>
        <th>Name</th>
        <th>Type</th>
    </tr>
    <tr>
        <td>UserID</td>
        <td>const unsigned int</td>
        <td>ManagerID</td>
        <td>const unsigned int</td>
        <td>PostID</td>
        <td>const unsigned int</td>
        <td>AppliedID</td>
        <td>const unsigned int</td>
    </tr>
    <tr>
        <td>User name</td>
        <td>String</td>
        <td>User name</td>
        <td>String</td>
        <td>Location</td>
        <td>int</td>
        <td>PostID</td>
        <td>const unsigned int</td>
    </tr>
    <tr>
        <td>Full name</td>
        <td>String</td>
        <td>Full name</td>
        <td>String</td>
        <td>Type</td>
        <td>int</td>
        <td>UserID</td>
        <td>const unsigned int</td>
    </tr>
    <tr>
        <td>ID</td>
        <td>long</td>
        <td>Posts</td>
        <td>Array[unsigned int]</td>
        <td>Profession</td>
        <td>int</td>
        <td>Description</td>
        <td>String</td>
    </tr>
    <tr>
        <td>Age</td>
        <td>int</td>
        <td>Password</td>
        <td>String</td>
        <td>Name</td>
        <td>String</td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>Phone number</td>
        <td>String</td>
        <td></td>
        <td></td>
        <td>Description</td>
        <td>String</td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>Password</td>
        <td>String</td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>Resume</td>
        <td>String</td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
    </tr>
</table>
