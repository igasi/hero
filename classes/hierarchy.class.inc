<?php

requiere_once('results.class.inc');

class ero_hierarchy extends ero_results {
	
	//Properties definition
	private $results_hierarchy = array(
								'parent' => NULL;
								'parents' => array();
								'child' => NULL;
								'childs' => array();
								'errors' => array();
								);
	private $reference_field;

	//contructor
	function __construct($nid){
		$this->current_nid = $nid;
	}

	//functions define abstract in ero_results
	private function set_results(){
		$this->results['hierarchy'] = $this->results_hierarchy;
	}

	//methods for this class
	private function set_errors($error){
		$this->results_hierarchy['errors'] => array($error);
	}


/*
* functions for get parents and childs
*/

	private function ero_get_parent($reference_field=NULL){
		if ($reference_field != NULL){
			$this->results_hierarchy['parent'] = 
				db_query("SELECT field_".$reference_field."_target_id 
					FROM {field_data_field_".$reference_field."} 
					WHERE entity_id=:nid", 
					array(':nid'=>$this->current_nid) )-> fetchField();
		}else{
			set_errors($not_parent = 'No specific the reference_field(entity reference field)');
		}
	}

	private function ero_get_all_parents($reference_field=NULL){
		if ($reference_field != NULL){
			$this->results_hierarchy['parents'] = 
				db_query("SELECT entity_id 
					FROM {field_data_field_".$reference_field."} 
					WHERE field_".$reference_field."_target_id=:nid", 
					array(':nid'=>$this->current_nid) );
		}
	}

	private function ero_get_child($reference_field=NULL){
		if ($reference_field != NULL){
			$this->results_hierarchy['child'] =  
				db_query("SELECT entity_id 
					FROM {field_data_field_".$reference_field."} 
					WHERE field_".$reference_field."_target_id=:nid", 
					array(':nid'=>$this->current_nid) )-> fetchField();
		}
	}

	private function ero_get_allchilds($reference_field=NULL){
		if ($reference_field != NULL){
			$this->results_hierarchy['childs'] =  
				db_query("SELECT entity_id 
					FROM {field_data_field_".$reference_field."} 
					WHERE field_".$reference_field."_nid=:nid", 
					array(':nid'=>$this->current_nid) );
		}
	}




}