<?php
  class Request{
    protected $server_data;

    function __construct($server_data){
      $this->server_data = $server_data;
    }

    function getMethod(){
      return strtolower($this->server_data['REQUEST_METHOD']);
    }

    function getPath(){
      return $this->server_data['REQUEST_URI'];
    }

    function getUserAgent(){
      return $this->server_data['HTTP_USER_AGENT'];
    }

    function getURL(){
      return 'http'.(isset($this->$server_data['HTTPS']) ? 's' : '').'://'.$this->server_data['HTTP_HOST'].'/'.$this->server_data['REQUEST_URI'];
    }
  }

  class GetRequest extends Request{
    function getData(){
      parse_str($this->server_data['QUERY_STRING'], $query_string);
      
      return json_encode($query_string);
    }
  }
?>