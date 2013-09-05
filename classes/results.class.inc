<?php

/*
*igasi
*/

abstract class ero_results {
	
	//Properties definition
	protected $current_nid = NULL;
	protected $results = array(
							'arithmetic' => array(),
							'dbo' => array(),
							'hierarchy' => array()
							);



	//Definition abstract functions for hierarchy class
	abstract protected function setresults();


	//Definition methods for get results
	public function get_current_nid(){
		return $this->current_nid;
	}

	public function get_results_all(){
		return $this->results;
	}

	public function get_results_arithmetic(){
		return $this->results['arithmetic'];
	}

	public function get_results_dbo(){
		return $this->results['dbo'];
	}

	public function get_results_hierarchy(){
		return $this->results['hierarchy'];
	}



}