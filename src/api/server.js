const express = require('express');
const admin = require('firebase-admin');
const cors = require('cors');

// Initialize Firebase Admin SDK
const serviceAccount = require('./serviceAccountKey.json');

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
});

const db = admin.firestore();

// Create Express app
const app = express();
app.use(cors());
app.use(express.json());

/* 
#########################
## COLLECTION SECTION  ##
#########################
*/

// Read all collections
app.get('/api/collections', async (req, res) => {
    try {
        // Fetch all collections in the Firestore database in array format
        const collections = await db.listCollections();
        // Extract the collection names from the array
        const collectionNames = collections.map(col => col.id);

        res.status(200).json({collections: collectionNames});
        // res.redirect('http://192.168.1.28/collectionGet');
    } catch (error) {
        console.error('Error fetching collections:', error);
        res.status(500).json({ message: 'Error fetching collections' });
    }
  }
);


// Read a specific collection
app.get('/api/:collection', async (req, res) => {
  const { collection } = req.params;

  try {
    const snapshot = await db.collection(collection).get();
    const data = snapshot.docs.map(doc => ({ id: doc.id, ...doc.data() }));
    res.status(200).json(data);
  } catch (error) {
    console.error('Error fetching data:', error);
    res.status(500).json({ message: 'Error fetching data' });
  }
});

// Update a document in a Firestore collection
app.patch('/api/:collection/:id', async (req, res) => {
    const { collection, id } = req.params; // Extract collection name and document ID from the URL
    const updatedData = req.body; // Data to update from the request body
  
    try {
      // Update the document with the given ID
      await db.collection(collection).doc(id).update(updatedData);
  
      res.status(200).json({ message: `Document '${id}' in collection '${collection}' updated successfully` });
    } catch (error) {
      console.error('Error updating document:', error);
      res.status(500).json({ message: `Error updating document '${id}' in collection '${collection}'` });
    }
});
  

// Get a single document by ID (user)
app.get('/api/:collection/:id', async (req, res) => {
  const { collection, id } = req.params;

  try {
    const doc = await db.collection(collection).doc(id).get();
    if (doc.exists) {
      res.status(200).json({ id: doc.id, ...doc.data() });
    } else {
      res.status(404).json({ message: 'Document not found' });
    }
  } catch (error) {
    console.error('Error fetching document:', error);
    res.status(500).json({ message: 'Error fetching document' });
  }
});

// Create a new document in a Firestore collection
app.post('/api/:collection/:id', async (req, res) => {
    const { collection, id } = req.params; // Collection name and document ID from the URL
    const data = req.body; // Data sent in the request body
  
    try {
      // Add or overwrite the document with the specified ID
      await db.collection(collection).doc(id).set(data);
  
      res.status(201).json({ message: 'Document created', id });
    } catch (error) {
      console.error('Error creating document:', error);
      res.status(500).json({ message: 'Error creating document' });
    }
  });
  
  

app.delete('/api/:collection/:id', async (req, res) => {
    const {collection, id} = req.params;

    try {
      await db.collection(collection).doc(id).delete();
      res.status(200).json({ message: `Document ${id} deleted` });
    }
    catch (error) {
      console.error('Error deleting document:', error);
      res.status(500).json({ message: 'Error deleting document' });
    }
})
// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
