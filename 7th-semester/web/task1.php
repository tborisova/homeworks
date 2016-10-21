function show_page($data, $title){

    foreach( $data as $key => $values ){
        if($key == $title){
          return "<h1>".$values['title']."</h1>
                  <h2>".$values['lecturer']."</h2>
                  <p>".$values['description']."</p>";
        }
    }
};