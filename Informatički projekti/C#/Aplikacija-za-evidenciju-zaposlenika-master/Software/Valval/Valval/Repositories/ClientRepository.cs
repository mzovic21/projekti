using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DBLayer;
using Valval.Models;

namespace Valval.Repositories {
    internal class ClientRepository {

        public static Client GetClient(int id) {
            Client client = null;
            string sql = $"SELECT * FROM Clients WHERE Id = {id}";
            DB.OpenConnection();
            var reader=DB.GetDataReader(sql);
            if(reader.HasRows) {
                reader.Read();
                client = CreateObject(reader);
                reader.Close();
            }
            DB.CloseConnection();
            return client;
        }

        public static List<Client> GetClients() {
            List<Client> clients = new List<Client>();

            string sql = "SELECT * FROM Clients";
            DB.OpenConnection();
            SqlDataReader reader = DB.GetDataReader(sql);

            while(reader.Read()) {
                Client client = CreateObject(reader);
                clients.Add(client);
            }
            reader.Close();
            DB.CloseConnection();
            return clients;
        }

        private static Client CreateObject(SqlDataReader reader) {
            int id = int.Parse(reader["Id"].ToString());
            string firstName = reader["FirstName"].ToString();
            string lastName = reader["LastName"].ToString();
            string typeOfService = reader["TypeOfService"].ToString();
            string location = reader["Location"].ToString();
            string contact = reader["Contact"].ToString();

            var client = new Client {
                Id = id,
                FirstName = firstName,
                LastName = lastName,
                TypeOfService = typeOfService,
                Location = location,
                Contact = contact
            };

            return client;
        }

        public static void AddClient(int id, string firstName, string lastName, string location, string contact, string typeOfService) {
            string sql = $"INSERT INTO Clients (Id, FirstName, LastName, Location, Contact, TypeOfService) VALUES ('{id}', '{firstName}', '{lastName}', '{location}', '{contact}', '{typeOfService}')";
            DB.OpenConnection();
            DB.ExecuteCommand(sql);
            DB.CloseConnection();
        }

        public static void DeleteClient(int id) {
            string sql = $"DELETE FROM Clients WHERE Id = {id}";

            DB.OpenConnection();
            DB.ExecuteCommand(sql);
            DB.CloseConnection();
        }

        public static void UpdateClient(int id, string firstName, string lastName, string location, string contact, string typeOfService) {
            string sql = $"UPDATE Clients SET FirstName = '{firstName}', LastName = '{lastName}', Location = '{location}', Contact = '{contact}', TypeOfService = '{typeOfService}' WHERE Id = {id}";

            DB.OpenConnection();
            DB.ExecuteCommand(sql);
            DB.CloseConnection();
        }

    }
}
