<?php

/*
* Function rules integration
* Implements hook_rules_action_info().
*/

function cec_custom_rules_action_info() {
	$return = array(
	//denine rule for insert node registration
		'insert_node_resgitration' => array(
		'label' => t('Update data when insert node registration'),
		'parameter' => array(
		  'nid' => array(
			'type' => array('decimal'),
			'label' => t('Enter node nid'),
			'description' => t('Update data when insert node registration'),
		  ),
		),
		'group' => t('Custom kerstendirect'),
		'base' => 'cec_custom_action_insert_registration',
		'provides' => array(
		  'insert_registration' => array(
			'type' => 'decimal',
			'label' => t('Values result insert registration'),
		  ),
		),
	  ),
	  //denine rule for delete node registration       
		 'delete_node_registration' => array(                         
		   'label' => t('Update data when delete node registration'),      
		   'parameter' => array(                 
			 'nida' => array(                    
			   'type' => array('decimal'),       
			   'label' => t('Enter node nid'),   
			   'description' => t('Update data when delete node registration'),
			 ),                                  
		   ),                                    
		   'group' => t('Custom kerstendirect'),
		   'base' => 'cec_custom_action_delete_registration',                                                                                      
		   'provides' => array(                  
			 'delete_registration' => array(               
			   'type' => 'decimal',              
			   'label' => t('Values result delete registration'),        
			 ),                                  
		   ),                                    
		 ),
	);

	return $return;
}
