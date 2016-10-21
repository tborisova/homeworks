function show_nav($data, $selected_course){

  $nav = "<nav>";
  foreach($data as $key => $values){
    if($key == $selected_course){
        $nav = $nav."<a href='?page=".$key."' class='selected'>".$values['title']."</a>";
    }else{
        $nav = $nav."<a href='?page=".$key."'>".$values['title']."</a>";
    }
  }

  $nav = $nav."</nav>";
  return $nav;
};