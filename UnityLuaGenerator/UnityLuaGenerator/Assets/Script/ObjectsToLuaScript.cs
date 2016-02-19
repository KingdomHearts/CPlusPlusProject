using UnityEngine;
using System.Collections.Generic;
using System.IO;

public class ObjectsToLuaScript : MonoBehaviour {

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

        //export every Gameobject to a single lua file
        //File.Create("../../mge_student_edition_v15.0.0/assets/mge/lua/test.lua");

        StreamWriter file = new StreamWriter("../../mge_student_edition_v15.0.0/assets/mge/lua/AssetLoader.lua");
        foreach (Transform child in transform)
        {

            //string Name = GO.GetComponentInChildren<Material>().GetTexture(0).name;

            file.WriteLine("AddModel('" +
                child.gameObject.name + "','" +
                child.gameObject.name + ".obj','" +
                "" + "'," +
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
//                child.gameObject.transform.position.x + "," +
//                child.gameObject.transform.position.y + "," +
//                child.gameObject.transform.position.z + "','" +
//                child.gameObject.transform.rotation.eulerAngles.y + "')");
        }
        file.Close();
        
		/**/
        string sourcePath = "Assets/";
        string targetPath = "../../mge_student_edition_v15.0.0/assets/mge/";


        if (System.IO.Directory.Exists(sourcePath + "Models"))
        {
            string[] files = System.IO.Directory.GetFiles(sourcePath + "Models", "*.obj");

            // Copy the files and overwrite destination files if they already exist.
            foreach (string s in files)
            {
                // Use static Path methods to extract only the file name from the path.
                string fileName = System.IO.Path.GetFileName(s);
                string destFile = System.IO.Path.Combine(targetPath + "models", fileName);
                System.IO.File.Copy(s, destFile, true);
            }
        }

        if (System.IO.Directory.Exists(sourcePath + "Textures"))
        {
            string[] files = System.IO.Directory.GetFiles(sourcePath + "Textures", "*.png");

            // Copy the files and overwrite destination files if they already exist.
            foreach (string s in files)
            {
                // Use static Path methods to extract only the file name from the path.
                string fileName = System.IO.Path.GetFileName(s);
                string destFile = System.IO.Path.Combine(targetPath + "textures", fileName);
                System.IO.File.Copy(s, destFile, true);
            }
        }
        /**/


    }
	
	// Update is called once per frame
	void Update () {
	}
}
