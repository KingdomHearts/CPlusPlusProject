using UnityEngine;
using System.Collections;

public class PuzzleScript : MonoBehaviour {

    [SerializeField]
    private Vector3 _finalPosition;

    public Vector3 FinalPosition { get { return _finalPosition; } set { _finalPosition = value; } }
}
