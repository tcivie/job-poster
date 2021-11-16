#ifndef MANAGER
#define MANAGER

/*  Helper function to print a specific job post
    :param post: post
    :return: None (just print)
*/  void view_post(Post post);

/*  Requiremrnt 2.4 - Function of printing all the job posts
    :param manager: logged in manager
    :param post: post
    :return: None (just print)
*/  void view_posts(Manager manager, Post post);

/*  Requiremrnt 2.2 - Function of adding a new job post
    :return: Post*
*/  Post* add_new_post();






#endif

