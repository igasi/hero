<?php


requiere_once('results.class.inc');

class ero_dbo extends ero_results {

	//Properties definition
	private $results_dbo = array(
								'inserts' => array();
								'deletes' => array();
								'updates' => array();
								'queries' => array();
								'errors' => array();
								);
	private $entity_type = 'node';
	private $bundle;
	private $deleted = 0;
	private $entity_id = $this->current_nid;
	private $revision_id = $this->current_nid;
	private $language = 'und';
	private $delta = 0;
	private $field = NULL;
	private $value = NULL;
	private $reference_field = NULL;
	


	//contructor
	function __construct($nid){
		$this->current_nid = $nid;
	}

	//functions define abstract in ero_results
	private function set_results(){
		$this->results['dbo'] = $this->results_dbo;
	}

	//methods for this class
	private function set_errors($error){
		$this->results_dbo['errors'] => array($error);
	}




	/*
	* Auxiliar Functions Active Record for fields
	*/

	//implements db_insert
	function _ero_field_dbinsert($bundle=NULL,$field=NULL,$value=NULL,$nid=NULL)
	{
		return db_insert('field_data_field_'.$campo)
				->fields(array('entity_type'=>'node',
								'bundle'=>$bundle,
								'deleted'=>0,
								'entity_id'=>$nid,
								'revision_id'=>$nid,
								'language'=>'und',
								'delta'=>0,
								'field_'.$field.'_value'=>$value,
				))
				->execute();
	}

	//implements db_delete
	function _ero_field_dbdelete($field=NULL,$nid=NULL){
		return db_delete('field_data_field_'.$field)
				->condition('entity_id',$nid, '=')
				->execute();
	}

	//implements db_update
	function _ero_field_dbupdate($field=NULL,$value=NULL,$nid=NULL){
		return db_update('field_data_field_'.$field)
				->fields(array('field_'.$field.'_value' => $value))
				->condition('entity_id',$nid,'=')
				->execute();
	}

	//implements db_query
	function _get_field_value($field=NULL,$nid=NULL){
		return db_query("SELECT field_".$field."_value 
						FROM {field_data_field_".$field."} 
						WHERE entity_id=:nid", 
						array(':nid'=>$nid) )-> fetchField();
	}




	//desctruct
	function __destruct(){
		unset($this);
	}

}