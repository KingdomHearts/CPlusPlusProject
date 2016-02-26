using UnityEngine;
using System.Collections.Generic;
using System.IO;

public class ObjectsToLuaInteractableScript : MonoBehaviour {

    // Use this for initialization
    void Start()
    {
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

        

        StreamWriter file = new StreamWriter("../../mge_student_edition_v15.0.0/assets/mge/lua/AssetLoaderInteractable.lua");
        foreach (Transform child in transform)
        {
            string texture = "";
            if (child.gameObject.GetComponentInChildren<Renderer>())
            {
                if (child.gameObject.GetComponentInChildren<Renderer>().material.mainTexture)
                {
                    texture = child.gameObject.GetComponentInChildren<Renderer>().material.mainTexture.name;
                    string[] Texture = texture.Split(new char[' ']);
                    texture = Texture[0] + ".tga";
                }
            }

            Vector3 position = new Vector3(
                child.GetComponent<PuzzleScript>().FinalPosition.x,
                child.GetComponent<PuzzleScript>().FinalPosition.y,
                child.GetComponent<PuzzleScript>().FinalPosition.z);

            Quaternion rotation = Quaternion.Euler(
                child.GetComponent<PuzzleScript>().FinalRotation.x, 
                child.GetComponent<PuzzleScript>().FinalRotation.y, 
                child.GetComponent<PuzzleScript>().FinalRotation.z);

            Vector3 scale = new Vector3(
                child.GetComponent<PuzzleScript>().FinalScale.x,
                child.GetComponent<PuzzleScript>().FinalScale.y,
                child.GetComponent<PuzzleScript>().FinalScale.z);

            Matrix4x4 matrix = Matrix4x4.TRS(position, rotation, scale);

            file.WriteLine("AddInteractiveModel('" +
                child.gameObject.name + "','" +
                child.gameObject.name + ".obj','" +
				texture + "'," + /*TEXTURE*/
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
                child.gameObject.transform.localToWorldMatrix.m33 + "," +

                matrix.m00 + "," +
                matrix.m10 + "," +
                matrix.m20 + "," +
                matrix.m30 + "," +
                matrix.m01 + "," +
                matrix.m11 + "," +
                matrix.m21 + "," +
                matrix.m31 + "," +
                matrix.m02 + "," +
                matrix.m12 + "," +
                matrix.m22 + "," +
                matrix.m32 + "," +
                matrix.m03 + "," +
                matrix.m13 + "," +
                matrix.m23 + "," +
                matrix.m33 + ")");
        }
        file.Close();


    }

    // Update is called once per frame
    void Update()
    {
    }
}
