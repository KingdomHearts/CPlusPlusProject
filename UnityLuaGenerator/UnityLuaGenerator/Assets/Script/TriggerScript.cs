using UnityEngine;
using System.Collections.Generic;
using System.IO;

public class TriggerScript : MonoBehaviour {

	// Use this for initialization
	void Start () {
        List<GameObject> ChildsList = new List<GameObject>();
        Transform[] ChildsArray = gameObject.GetComponentsInChildren<Transform>();
        if (ChildsArray == null)
        {
            Debug.Log("There are no models to be exported");
            return;
        }
        foreach (Transform t in ChildsArray)
        {
            if (t != null && t.gameObject != null)
                ChildsList.Add(t.gameObject);
        }

		/**/
        StreamWriter file = new StreamWriter("../../mge_student_edition_v15.0.0/assets/mge/lua/Triggers.lua");
        foreach (Transform child in transform)
        {
            file.WriteLine("TriggerObject('" +
                child.gameObject.name + "'," +
                child.gameObject.transform.lossyScale.x / 2 + "," +
                child.gameObject.transform.localToWorldMatrix.m00 + "," +
                child.gameObject.transform.localToWorldMatrix.m10 + "," +
                child.gameObject.transform.localToWorldMatrix.m20 + "," +
                child.gameObject.transform.localToWorldMatrix.m30 + "," +
                child.gameObject.transform.localToWorldMatrix.m01 + "," +
                child.gameObject.transform.localToWorldMatrix.m11 + "," +
                child.gameObject.transform.localToWorldMatrix.m21 + "," +
                child.gameObject.transform.localToWorldMatrix.m31 + "," +
                child.gameObject.transform.localToWorldMatrix.m02 + "," +
                child.gameObject.transform.localToWorldMatrix.m12 + "," +
                child.gameObject.transform.localToWorldMatrix.m22 + "," +
                child.gameObject.transform.localToWorldMatrix.m32 + "," +
                child.gameObject.transform.localToWorldMatrix.m03 + "," +
                child.gameObject.transform.localToWorldMatrix.m13 + "," +
                child.gameObject.transform.localToWorldMatrix.m23 + "," +
                child.gameObject.transform.localToWorldMatrix.m33 + ")");
        }
        file.Close();
        /**/
    }
}
